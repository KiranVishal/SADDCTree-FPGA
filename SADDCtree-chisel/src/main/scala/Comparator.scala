package saddc

import Chisel._


class ComparatorReq extends SADDCBundle {
	val feature = SInt(INPUT, width=32)
	val weights = SInt(INPUT, width=32)
  val index = UInt(INPUT)
}

class ComparatorResp extends SADDCBundle {
	val decision = UInt(OUTPUT, width=1)
  val index = UInt()
}

class ComparatorInterface extends SADDCBundle {
	val req = Decoupled(new ComparatorReq).flip
	val resp = Decoupled(new ComparatorResp)
}

class Comparator extends SADDCModule {
  val io = new ComparatorInterface
  val dataOut = UInt(OUTPUT, width=1)

  io.resp.bits.index := io.req.bits.index
<<<<<<< HEAD
  io.resp.bits.decision := dataOut 
=======
  // io.req.ready := Bool(false)
  // io.resp.valid := Bool(false)
  io.resp.bits.decision := dataOut

>>>>>>> 90f386b2bacbf5150c518da5b7ca45be3abb3225

  when (io.req.bits.feature <= io.req.bits.weights) {
  		dataOut := UInt(1)
      }.otherwise {
      dataOut := UInt(0)
      }
}
// class ComparatorTests(uut: Comparator, isTrace: Boolean = true) extends Tester(uut, isTrace){
// 	val lim = 60
// 	var f = 0
// 	var w = 0
// 	var out = 0
//   for (t <- 0 until 10) { 
//   f = rnd.nextInt(lim)
//   w = rnd.nextInt(lim)
//   poke(uut.io.req.bits.feature, f) 
//   poke(uut.io.req.bits.weights, w)
// 	if(f <= w)
// 	{
// 	out = 1
// 	}else{
// 	out = 0
// 	}
// 	expect(uut.io.resp.bits.decision, out) 
//   step(1) 
//   } 
// }


// object comp {
//   def main(args: Array[String]): Unit = {
//   chiselMainTest(args, () => Module(new Comparator, {case No_Comparator=> 10} )) {
//     c => new ComparatorTests(c) 
//   }
//   }
// }
