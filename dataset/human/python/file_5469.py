import scala.math._

object Main extends App {
  val sc = new java.util.Scanner(System.in)
  val x, y = sc.next

  val ans = if (x < y) "<" else if (x > y) ">" else "="

  println(ans)

  ///////////////////////////////////////////

  def bigIterator(start: BigInt, end: BigInt, step: BigInt = 1) =
    Iterator.iterate(start)(_ + step).takeWhile(_ <= end)

  def lcm(a :Int, b :Int): Int =
    a / gcd(a, b) * b

  def lcm(a :Long, b :Long): Long =
    a / gcd(a, b) * b

  def gcd(a: Int, b: Int): Int =
    if (b == 0) a else gcd(b, a % b)

  def gcd(a: Long, b: Long): Long =
    if (b == 0) a else gcd(b, a % b)

  def setOrUpdated[A, B](a: Map[A, B], key: A, value: B, f: (B, B) => B) =
    a.get(key) match {
      case Some(v) => a.updated(key, f(value, v))
      case _ => a + (key -> value)
    }
}
