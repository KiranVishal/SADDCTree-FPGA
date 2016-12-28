package saddc

import Chisel._

abstract trait ControlUnitParameters extends SADDCParameters {
}

class ControlUnitInterface extends SADDCBundle with ControlUnitParameters{
  // val fBlock = Vec.fill(n_comparator){SInt(INPUT, 32)}
  // val wBlock = Vec.fill(n_comparator){SInt(INPUT, 32)}
  // val decision = Vec.fill(n_comparator){UInt(OUTPUT, 1)}
  val fBlock = SInt(INPUT, 32)
  val wBlock = SInt(INPUT, 32)
  val decision = UInt(OUTPUT, 1)
}


class ControlUnit extends SADDCModule with ControlUnitParameters{
  val io = new ControlUnitInterface
  val comp = Vec.fill(n_comparator){Module (new Comparator()).io}

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
  for (t <- 0 until 10) { 
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
    expect(uut.io.decision, out) 
    step(1) 
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