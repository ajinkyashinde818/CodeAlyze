import scala.io.{StdIn => in}

object Main extends App {

  val mod = 1000000007L

  val n = in.readInt
  val s = in.readLine

  val table = Array.ofDim[Long]('z' - 'a' + 1)
  for(ch <- s)
    table(ch - 'a') += 1

  val ans = table.filter(i => i > 0)./:(1L) { (acc, i) =>
      acc * (i+1) % mod
    } - 1
  println(ans)
}
