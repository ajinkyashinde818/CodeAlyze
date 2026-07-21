object Main extends App {
  import scala.io.StdIn._
  def num(a: Long, b: Long): Long = {
    val x = a % b
    if(x == 0) return b
    else num(b, x)
  }
  val Array(a, b) = readLine().split(" ").map(_.toLong)
  val x = num(a, b)
  val ans = a * (b / x)
  println(ans)
}
