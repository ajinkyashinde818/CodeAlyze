import scala.io.StdIn._
import scala.math.abs

object Main extends App {
  val N = readLine.toInt
  val A = readLine.split(' ').map(s => s.toLong)

  def calcAbsSum(a: Array[Long]): Long = a.map(abs(_))sum

  if (A.exists(x => x == 0)) {
    println(calcAbsSum(A))
  } else if (A.filter(x => x < 0).size % 2 == 0) {
    println(calcAbsSum(A))
  } else {
    val min_v = A.map(abs(_)).min
    println(calcAbsSum(A) - min_v*2)
  }
}
