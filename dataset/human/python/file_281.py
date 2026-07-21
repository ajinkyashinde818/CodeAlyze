import scala.io.StdIn.readLine

object Main {
  def main(args: Array[String]) = {
    val n = readLine.map(_.toInt)
    val as = readLine.split(" ").map(_.toLong)
    if (as.count(x => x < 0) % 2 == 0) {
      println(as.map(Math.abs).sum)
    } else if (as.count(x => x <= 0) % 2 == 0) {
      println(as.map(Math.abs).sum)
    } else {
      val abs = as.map(Math.abs)
      println(abs.sum - abs.min * 2)
    }
  }
}
