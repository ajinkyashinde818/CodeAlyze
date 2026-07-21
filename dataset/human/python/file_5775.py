object Main extends App {

  val n = scala.io.StdIn.readInt()
  val a = scala.io.StdIn.readLine.split(" ").map(_.toInt)
  val b = scala.io.StdIn.readLine.split(" ").map(_.toInt)
  val c = scala.io.StdIn.readLine.split(" ").map(_.toInt)

  def solve(): Int = {
    var satisfiedValue = 0
    for(i <- 0 until n) {
      val index = a(i) - 1
      satisfiedValue += b(index)
      if(i != 0 && a(i) - a(i-1) == 1)
        satisfiedValue += c(index-1)
    }
    satisfiedValue
  }
  println(solve)
}
