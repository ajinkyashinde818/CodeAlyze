import scala.math._

object Main extends App {

  val YES = "YES"
  val Yes = "Yes"
  val NO = "NO"
  val No = "No"

  val input: Array[Array[Int]] = Array.ofDim(6, 6000000)
  ///////////////////////////////////////////

  val sc = new java.util.Scanner(System.in)
  val n = sc.nextInt
  val a = List.fill(n)(sc.nextInt)
  val b = List.fill(n)(sc.nextInt)
  val c = List.fill(n - 1)(sc.nextInt)

  val ans =
    a.foldLeft((0, -1)) { case ((acc, previousIndex), in) =>
      if (in - 1 == previousIndex) (acc + b(in - 1) + c(in - 2), in)
      else (acc + b(in - 1), in)
    }._1
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
