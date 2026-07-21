import scala.io.StdIn._

object Main extends App {

  val Array(n,k,s) = readLine().split(" ").map(_.toInt)
  def solve() = {
    val str = if(s == 1e9) {
      ((1e9.toInt).toString + ",") * k + "1," * (n-k)
    } else {
      (s.toString + ",") * k + ((s+1).toString + ",") * (n-k)
    }
    str.split(",").mkString(" ")
  }

  println(solve())

}
