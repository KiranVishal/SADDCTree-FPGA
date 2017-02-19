object Mem { 
  def apply[T <: Data](depth: Int, gen: => T, 
          seqRead: Boolean = false): Mem 
} 
 
class Mem[T <: Data](gen: () => T, depth: Int, 
      seqRead: Boolean = false) 
    extends Updateable { 
  def apply(idx: UInt): T 
}

val rf = Mem(32, UInt(width = 64)) 
when (wen) { rf(waddr) := wdata } 
val dout1 = rf(waddr1) 
val dout2 = rf(waddr2)
 