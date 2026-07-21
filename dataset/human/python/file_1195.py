import scala.io.{StdIn => in}

object Main extends App {
  val n = in.readInt

  val table = Array.ofDim[Long](n+1)
  val a = in.readLine.split(" ").map(_.toLong)
  (0 until n).foreach { i =>
    table(i+1) = table(i) + a(i)
  }

  val ans = (1 until n)./:(Int.MaxValue.toLong) { (acc, i) =>
    acc min ( table(i) - (table(n) - table(i)) ).abs
  }
  
  println(ans)
}
