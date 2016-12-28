package Chisel

import scala.collection.mutable.{ArrayBuffer, HashMap}
import java.io._
//template for FE chisel 
 def read_file(filename: String): String = {
    val buffer = new StringBuilder
    
    val n_node = UInt(0)
    val leaf_node = UInt(0)
    val nonleaf_node = UInt(0)

    val current_node[n] = 0  

    val left_node[n] = 0
    val right_node[n] = 0
    val feature_used[n] = 0
    val threshold[n] = 0
    
    val i = UInt(0)
    
    try {
      val reader = new BufferedReader(new FileReader(./FE_iris.csv))
      var line = ""
      while({line = reader.readLine(); line != null}) {
        buffer.append(line)
        buffer.append("\n")
        val line_array =line.split(" ")
        when (i == 0){
           n_node = line_array[0]
           leaf_node = line_array[1]
           nonleaf_node = line_array[2]
        } 
        .elsewhen((i!=0)&&(i!=n)){
          current_node[i] = line_array[0]
          left_node[i] = line_array[1]
          right_node[i] = line_array[2]
          feature_used[i] = line_array[3]
          threshold[i] = line_array[4]
        }
        i = i + 1
      }
      reader.close()
    } catch {
      case e: IOException => {
        System.err.println("Error reading file " + filename)
        System.exit(-1)
      }
    }
    buffer.toString()
  }


  // val myUInt= "hi hi"
  // val myU = myUInt.split(" ")
  // printf(myU(0))
  // printf(myU(1))