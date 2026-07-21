object Main {
  def main(args: Array[String]): Unit = {
    import scala.io.StdIn.readLine
    val Array(datK, datS) = readLine.split(" ").map(_.toInt)
    var count = 0
    for (x <- 0 to datK; y <- 0 to datK) {
      if((datS >= x + y) && (datS - (x + y) <= datK)) count += 1
    }
    println(count)
  }
}
