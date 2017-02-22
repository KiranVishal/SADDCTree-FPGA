package saddc

import Chisel._

abstract trait ControlUnitParameters extends SADDCParameters {
}

class ControlUnitInterface extends SADDCBundle with ControlUnitParameters{
  // val fBlock = Vec.fill(n_comparator){SInt(INPUT, 32)}
  // val wBlock = Vec.fill(n_comparator){SInt(INPUT, 32)}
  // val decision = Vec.fill(n_comparator){UInt(OUTPUT, 1)}
  val fBlock = SInt(INPUT, 32) // feature wire
  val wBlock = SInt(INPUT, 32) // treshold wire
  val decision = UInt(OUTPUT, 1)
  
  // Wres for total nodes, leaf nodes and non-leaf nodes
  val n_node = UInt(INPUT, 32) // total number of nodes wire
  val leaf_node = UInt(INPUT, 32)
  val nonleaf_node = UInt(INPUT, 32)

  // Wires for other features -> routed from a register file
  val current_node = UInt(INPUT, 32)
  val left_node = UInt(INPUT, 32)
  val right_node = UInt(INPUT, 32)
  val feature_index = UInt(INPUT, 32)

  //RegFile Wires
  val rPorts = Vec.fill(4) { UInt(INPUT, log2Up(1000)) }
  val rValues = Vec.tabulate(4) { i => gen(i).asOutput }
 
  val wPorts = Vec.fill(4) { Valid(UInt(width = log2Up(1000))).asInput }
  val wValues = Vec.tabulate(4) { i => gen(i).asInput }

  // Wire from Feature Extractor code
  val optN_comp = UInt(INPUT, 32)
}


class ControlUnit extends SADDCModule with ControlUnitParameters{
  val io = new ControlUnitInterface
  val comp = Vec.fill(n_comparator){Module (new Comparator()).io}
  val gen = () => Module(new RegFile(1000, 4, 4, i => Valid(UInt(OUTPUT, 32)))).io


  for (i <- 0 until n_comparator) {
    comp(i).req.bits.index := UInt(i)
    comp(i).req.bits.feature := io.fBlock
    comp(i).req.bits.weights := io.wBlock
  }
  // for (i <- 0 until n_comparator){
  //   io.decision(i) := comp(i).resp.bits.decision
  // }
  io.decision := comp(5).resp.bits.decision
}

  class ControlUnitTests(uut: ControlUnit, isTrace: Boolean = true) extends Tester(uut, isTrace){
  val lim = 60
  // var f = Array.fill(uut.n_comparator){0}
  // var w = Array.fill(uut.n_comparator){0}
  // var out = Array.fill(uut.n_comparator){0}
  var f = 0
  var w = 0
  var out = 0

//To test Register File
  val randVal = rnd.nextInt(1 << 32)
  val randValid = rnd.nextInt(2)
  val randRPort = rnd.nextInt(4)
  val randWPort = rnd.nextInt(4)
  val randReg = rnd.nextInt(32)

  for (t <- 0 until 20) { 



    f = rnd.nextInt(lim)
    w = rnd.nextInt(lim)
    poke(uut.io.fBlock, f) 
    poke(uut.io.wBlock, w)
    if(f <= w)
    {
      out = 1
    }else{
      out = 0
    }
    for (p <- 0 until 4) {
      if (p == randWPort) {
        poke(uut.io.wPorts(randWPort).valid, true)
        poke(uut.io.wPorts(randWPort).bits, randReg)
        poke(uut.io.wValues(randWPort).valid, randValid)
        poke(uut.io.wValues(randWPort).bits, randVal)
      } else {
        poke(uut.io.wPorts(p).valid, false)
      }
    }
    expect(uut.io.decision, out) 
    step(1) 
    poke(uut.io.rPorts(randRPort), randReg)
    step(0)
    expect(uut.io.rValues(randRPort).valid, randValid)
    expect(uut.io.rValues(randRPort).bits, randVal)
    } 
  }



  // for (t <- 0 until 10) { 
  //   for (i <- uut.n_comparator){
  //     f(i) = rnd.nextInt(lim)
  //     w(i) = rnd.nextInt(lim)
  //     if(f(i) <= w(i))
  //     {
  //     out(i) = 1
  //     }else{
  //     out(i) = 0
  //   }
  // }
  // poke(uut.io.fBlock, f) 
  // poke(uut.io.wBlock, w)
  // if (peek(uut.io.decision) == out)
  // {
  //   expect(true,true)
  // }
  // else{
  //   expect(true,false)
  // }
  // step(1) 
  // } 

object cont {
  def main(args: Array[String]): Unit = {
  chiselMainTest(args, () => Module(new ControlUnit, {case No_Comparator=> 10} )) {
    c => new ControlUnitTests(c) 
  }
  }
}