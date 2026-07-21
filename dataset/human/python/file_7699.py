import scala.math._

// longでrangeの作り方

object Main extends App {

  val YES = "YES"
  val Yes = "Yes"
  val NO = "NO"
  val No = "No"
  ///////////////////////////////////////////

  val sc = new java.util.Scanner(System.in)
  val x = sc.nextInt
//  val list = List.fill(3)(sc.next)

  val ans = if (x < 1200) "ABC" else "ARC"

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
