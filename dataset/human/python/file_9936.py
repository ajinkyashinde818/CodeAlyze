import scala.io.StdIn._

object Main extends App {


  val Array(a,b) = readLine().split(" ").map(_.toLong)

  def solve() = {
    calcLCM(a,b)
  }

  // Greatest Common Divisor
  def calcGCD(x: Long, y: Long): Long = {
    if(y == 0) x
    else calcGCD(y, x % y)
  }

  // Least Common Multiple
  def calcLCM(x: Long, y: Long): Long = {
    (x * y) / calcGCD(x, y)
  }

  println(solve())

}
