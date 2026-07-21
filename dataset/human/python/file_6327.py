import scala.io.{StdIn => in}

object Main extends App {
  val n = in.readLine.toLong

  def rec(i:Long, cnt:Long, b:Long): Long = {
    if(i < 10L) cnt
    else rec(i / b, cnt + i / 2L / b, b)
  }

  val ans = if(n % 2 == 1) 0 else rec(n, 0L, 5L)
  println(ans)
}
