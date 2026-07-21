import scala.io.StdIn._
object Main extends App {

  val n = readInt()
  val num = readLine.trim.split(' ').map(_.toLong)
  val max = num.map(math.abs)
  val parity = num.count{_ < 0} % 2
  println(
    if (parity == 0) max.sum
    else max.sum - max.min * 2
  )
}
