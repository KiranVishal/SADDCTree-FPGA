
// package saddc
// import Chisel._

// /**
//  * A parametrized register file.
//  *
//  * The value of a register can be read in the same cycle by changing the value
//  * of one of the read ports. The value of a register can be written on the clock
//  * edge in one cycle.
//  * 
//  * Also, each register can be defined to contain any subclass of `Chisel.Data`,
//  * so for example, a collection of 16 32-bit registers with valid bits that has
//  * 2 read ports and 1 write port could be created as:
//  *
//  *     new RegFile(16, 2, 1, r => Valid(UInt(width = 32)))
//  *
//  * To Read: Set one of the rPorts to the register number you wish to read. Then,
//  * the value will appear on the corresponding rValues wire.
//  *
//  * To Write: Set one of the wPorts to the register number you wish to write. Set
//  * the corresponding valid bit and wValues.
//  *
//  * Read ports are cheap. Write ports are expensive.
//  *
//  * @param size the number of registers.
//  * @param numRPorts the number of read ports.
//  * @param numWPorts the number of write ports.
//  * @param gen a function that takes an integer i and returns an instance of the
//  * register type. i is the register number.
//  */
// class RegFile [T <: Data](size: Int, numRPorts: Int, numWPorts: Int, gen: Int => T) extends Module with SADDCParameters{
//   val io = new Bundle {
//     val rPorts = Vec.fill(numRPorts) { UInt(INPUT, log2Up(size)) }
//     val rValues = Vec.tabulate(numRPorts) { i => gen(i).asOutput }
 
//     val wPorts = Vec.fill(numWPorts) { Valid(UInt(width = log2Up(size))).asInput }
//     val wValues = Vec.tabulate(numWPorts) { i => gen(i).asInput }
//   }

//   // The actual registers
//   val regs = Array.tabulate(size) { i => UInt(i, width = 32) -> Reg(gen(i)) }

//   // Hook up read ports with muxes to regs
//   for (i <- 0 until numRPorts) {
//     io.rValues(i) := MuxLookup(io.rPorts(i), gen(0), regs)
//   }

//   // Hook up write ports to regs
//   for (p <- 0 until numWPorts) {
//     for (r <- 0 until size) {
//       when (io.wPorts(p).valid && io.wPorts(p).bits === UInt(r)) {
//         regs(r)._2 := io.wValues(p)
//       }
//     }
//   }
// }

// class RegFileTests(c: RegFile[ValidIO[UInt]]) extends Tester(c) {
//   for (i <- 0 until 1000) {
//     val randVal = rnd.nextInt(1 << 32)
//     val randValid = rnd.nextInt(2)
//     val randRPort = rnd.nextInt(4)
//     val randWPort = rnd.nextInt(4)
//     val randReg = rnd.nextInt(32)

//     // Write to the registers
//     for (p <- 0 until 4) {
//       if (p == randWPort) {
//         poke(c.io.wPorts(randWPort).valid, true)
//         poke(c.io.wPorts(randWPort).bits, randReg)
//         poke(c.io.wValues(randWPort).valid, randValid)
//         poke(c.io.wValues(randWPort).bits, randVal)
//       } else {
//         poke(c.io.wPorts(p).valid, false)
//       }
//     }

//     // Then, read back
//     step(1)
//     poke(c.io.rPorts(randRPort), randReg)

//     step(0)
//     expect(c.io.rValues(randRPort).valid, randValid)
//     expect(c.io.rValues(randRPort).bits, randVal)
//   }
// }












package saddc

import Chisel._

class RegReq extends SADDCBundle {

  //Two Read Ports
  val r1Port = UInt(INPUT, width = 32) 
  //val r1data = UInt(INPUT, width = 32)
  
  val r2Port = UInt(INPUT, width = 32)
  //val r2data = UInt(INPUT, width = 32)

  //Address and Data to the write port
  val wPort = UInt(INPUT, width = 32)
  val wData = UInt(INPUT, width = 32)
}
 
class RegResp extends SADDCBundle{  
 
  //The data from the two read ports
  val r1Out = UInt(OUTPUT, width = 32)
  val r2Out = UInt(OUTPUT, width = 32)

}

class RegInterface extends SADDCBundle{

  val req = Decoupled(new RegReq).flip
  val resp = Decoupled(new RegResp)

}

class RegisterFile( Size : Int ) extends SADDCModule {

  val io = new RegInterface
  
  val d1Out = Reg(UInt(OUTPUT, width = 32))
  val d2Out = Reg(UInt(OUTPUT, width = 32))

  io.resp.bits.r1Out := io.req.bits.r1Port
  io.resp.bits.r2Out := io.req.bits.r2Port

  io.resp.bits.r1Out := d1Out
  io.resp.bits.r2Out := d2Out

  val ramMem = Mem(Size, UInt(width=32), seqRead = true)

  when (ren)
  {
    d1Out := ramMem(r1Port)
    d2Out := ramMem(r2Port)
  }
  .elsewhen(wen)
  {
    ramMem(wPort) := wData
  }


}



