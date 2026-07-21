import scala.io.StdIn._
object Main extends App {
  val n = readInt()
  val str = readLine.trim
  val count = ('a' to 'z').map(c ⇒ str.count(_ == c)).toArray
  val mod = 1000000007L
  println(
    (count.foldLeft(1L){(a, b) ⇒ a * (b + 1) % mod} - 1 + mod) % mod
  )
}
