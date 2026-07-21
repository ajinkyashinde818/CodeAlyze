import scala.annotation.tailrec
import scala.io.StdIn._
object Main extends App {

  loop()
  @tailrec def loop(): Unit = {
    val Array(n, k) = readLine.trim.split(' ').map(_.toLong)
    if (n == 0 && k == 0) return
    println(count(n - 1, k))
    loop()
  }
  def count(rest: Long, k: Long, digit: Int = 1): String = {
    val d = countDigit(digit)
    if (d * digit >= rest) makeString(rest % digit, k, power(10, digit - 1) + rest / digit)
    else count(rest - d * digit, k, digit + 1)
  }
  def makeString(rest: Long, k: Long, start: Long): String = {
    (start to start + k).mkString.substring(rest.toInt, rest.toInt + k.toInt)
  }
  def countDigit(digit: Int): Long = {
    power(10, digit) - power(10, digit - 1)
  }
  def power(base: Long, exp: Int): Long = {
    exp match {
      case 0 ⇒ 1L
      case 1 ⇒ base
      case _ ⇒ power(base * base, exp / 2) * power(base, exp % 2)
    }
  }
}
