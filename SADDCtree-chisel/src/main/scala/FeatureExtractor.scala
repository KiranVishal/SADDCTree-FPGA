 // package Chisel

// import scala.collection.mutable.{ArrayBuffer, HashMap}
// import java.io._
// //template for FE chisel 
//  def read_file(filename: String, n: Int): String = {
//     val buffer = new StringBuilder
    
//     val n_node = UInt(0, width = 32)
//     val leaf_node = UInt(0, width = 32)
//     val nonleaf_node = UInt(0, width = 32)

//     val current_node = Array.fill(n){UInt(0, width = 32)}  
//     val left_node = Array.fill(n){UInt(0, width = 32)}
//     val right_node = Array.fill(n){UInt(0, width = 32)} 
//     val feature_index = Array.fill(n){UInt(0, width = 32)} 
//     val threshold = Array.fill(n){UInt(0, width = 32)} 
    
//     val i = UInt(0, width = 32)
    
//     try {
//       val reader = new BufferedReader(new FileReader(filename))
//       var line = ""
//       while({line = reader.readLine(); line != null}) {
//         buffer.append(line)
//         buffer.append("\n")
//         val line_array =line.split(" ")
//         when (i == 0){
//            n_node = line_array[0]
//            leaf_node = line_array[1]
//            nonleaf_node = line_array[2]
//            printf("%d %d %d \n", n_node, leaf_node, nonleaf_node)
//         } 
//         .elsewhen((i!=0)&&(i!=n)){
//           current_node[i] = line_array[0]
//           left_node[i] = line_array[1]
//           right_node[i] = line_array[2]
//           feature_index[i] = line_array[3]
//           threshold[i] = line_array[4]
//           printf("%d %d %d %d \n", current_node[i], left_node[i], right_node[i], feature_index[i], threshold[i])
//         }
//         i = i + 1
//       }
//       reader.close()
//     } catch {
//       case e: IOException => {
//         System.err.println("Error reading file " + filename)
//         System.exit(-1)
//       }
//     }
//     buffer.toString()
//   }


//   // val myUInt= "hi hi"
//   // val myU = myUInt.split(" ")
//   // printf(myU(0))
//   // printf(myU(1))

package cont
import scala.collection.mutable.{ArrayBuffer, HashMap}
import java.io._
//import Chisel._
//template for FE chisel 



object cont {
  def main(args: Array[String]): Unit = {
  // chiselMainTest(args, () => Module(new ControlUnit, {case No_Comparator=> 10} )) {
  //   c => new ControlUnitTests(c) 
  printf("hiiiiiiii")
  //cont.read_file("./FE_iris.csv")
  //val line_arrayint1 = "1 2 3 4 5 6 7".split(" ").map(_.toInt).distinct
  //printf("%d %d %d", line_arrayint1(0), line_arrayint1(2), line_arrayint1(4))
  read_file("./FE_iris.csv")
  }
 def read_file(filename: String): String = {
  val buffer = new StringBuilder
  
  var n_node = 0
  var leaf_node = 0
  var nonleaf_node = 0
  var i = 0
  var optN_comp = 0
  try{
    
    val reader = new BufferedReader(new FileReader(filename))
    var line = ""
    
    line = reader.readLine()
    buffer.append(line)
    buffer.append("\n")
    val line_arrayint = line.split(" ").map(_.toInt).distinct
    //val line_arrayint = line_array.map(x => x.toInt)
    n_node = line_arrayint(0)
    leaf_node = line_arrayint(1)
    nonleaf_node = line_arrayint(2)
    optN_comp = (n_node * 4) / 100
    i = i + 1
    printf("%d %d %d The number of comparators to be instantiated is %d \n", n_node, leaf_node, nonleaf_node, optN_comp)
  
    val current_node = Array.fill(n_node){0}  
    val left_node = Array.fill(n_node){0}
    val right_node = Array.fill(n_node){0} 
    val feature_index = Array.fill(n_node){0} 
    val threshold = Array.fill(n_node){0.0} 
    i = 0
    while({line = reader.readLine(); line != null}) {
      buffer.append(line)
      buffer.append("\n")
      val line_array =line.split(" ")
        current_node(i) = line_array(0).toInt
        left_node(i) = line_array(1).toInt
        right_node(i) = line_array(2).toInt
        feature_index(i) = line_array(3).toInt
        threshold(i) = line_array(4).toDouble
        printf("%d \n", i  )
        printf("%d %d %d %d \n", current_node(i), left_node(i), right_node(i), feature_index(i), threshold(i))
      i = i + 1
    }
    reader.close()
  }
  catch {
    case e: IOException => {
      System.err.println("Error reading file 1 " + filename)
      System.exit(-1)
    }
  }
  buffer.toString()
}
 }
  // val myUInt= "hi hi"
  // val myU = myUInt.split(" ")
  // printf(myU(0))
  // printf(myU(1))