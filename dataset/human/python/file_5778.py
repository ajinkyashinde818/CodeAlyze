object Main extends App {

  import scala.io.StdIn._

  val n = readInt
  val a = readLine.split("[ ]+").map(_.toInt)
  var sum = readLine.split("[ ]+").map(_.toInt).sum
  val c = readLine.split("[ ]+").map(_.toInt)
  for (i <- 0 until n - 1) {
    if (a(i + 1) == a(i) + 1)
      sum += c(a(i) - 1)
  }
  println(sum)
}
