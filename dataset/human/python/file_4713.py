import scala.io.StdIn

object Main extends App {
  val s = StdIn.readLine().sorted
  val t = StdIn.readLine().sortBy(f => -1*f)
  
  def loop(sl: String, tl: String): Boolean = {
    if(sl.nonEmpty && tl.isEmpty) false
    else if(sl.isEmpty && tl.nonEmpty) true
    else if(sl.isEmpty && tl.isEmpty) false
    else if(sl.head > tl.head) false
    else if(sl.head < tl.head) true
    else loop(sl.tail, tl.tail)
  }
  
  println(if(loop(s, t)) "Yes" else "No")
}
