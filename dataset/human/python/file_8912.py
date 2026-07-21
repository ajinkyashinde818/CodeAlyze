import scala.util.control.Breaks

object Main{
  def main(args: Array[String]) {
    val sc = new java.util.Scanner(System.in)
    var s = sc.next

    s = s.reverse

    val words = Seq("dream", "dreamer", "erase", "eraser").map{_.reverse}

    var flag = true
    val b = new Breaks
    b.breakable { while (flag) {
      flag = false
      words.foreach{ w =>
        if (s.take(w.size) == w) {
          s = s.drop(w.size)
          flag = true
        }
      }
    } }
    if (s.size == 0)
      println("YES")
    else
      println("NO")
  }
}
