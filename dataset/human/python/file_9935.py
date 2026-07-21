import scala.io.{StdIn => in}

object Main extends App {
  val Array(a, b) = in.readLine.split(" ").map(_.toLong)

  def rec(a:Long, b:Long):Long = {
    if(b == 0) a
    else rec(b, a % b)
  }

  val ans = a / rec(a, b) * b
  println(ans)
}
