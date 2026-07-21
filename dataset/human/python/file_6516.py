import scala.collection.mutable.ArrayBuffer
import scala.io.StdIn.readLine

object Main {
  def main(args: Array[String]): Unit = {
    solve
  }

  def solve(): Unit = {
    val sc = new java.util.Scanner(System.in)
    val s = readLine
    val q = readLine.toInt
    val lines = new Array[String](q)
    for(i <- 0 until q) {
      lines(i) = readLine()
    }

    var reversed = false
    val prefix = new ArrayBuffer[String]()
    val suffix = new ArrayBuffer[String]()

    for (i <- 0 until q) {
      val line = lines(i)
      val t = line.split(" ")(0).toInt
      if (t == 1) {
        reversed = !reversed
      } else {
        val f = line.split(" ")(1).toInt
        val c = line.split(" ")(2)
        if (f == 1) {
          if (!reversed) {
            prefix.append(c)
          } else {
            suffix.append(c)
          }
        } else {
          if (!reversed) {
            suffix.append(c)
          } else {
            prefix.append(c)
          }
        }
      }
    }


    if (!reversed) {
      print(prefix.toList.reverse.mkString(""))
      print(s)
      print(suffix.mkString(""))
    } else {
      (suffix.toList.reverse ++ s.reverse ++ prefix).mkString("")
      print(suffix.toList.reverse.mkString(""))
      print(s.reverse)
      print(prefix.mkString(""))

    }

  }
}
