import scala.io.StdIn

object Main {

  type State = Tuple3[Int, Int, Long]

  def update(state: State, num: Int): State = {
    val isMinus = if (num >= 0) 0 else 1
    val absNum = Math.abs(num)
    val sum = state._3 + (absNum: Long)

    Tuple3(state._1 + isMinus, if (state._2 >= absNum) absNum else state._2, sum)
  }

  def maxPossibleValue(state: State): Long = {
    if (state._1 % 2 == 0) state._3 else state._3 - (2 * state._2: Long)
  }

  def main(args: Array[String]): Unit = {
    val n = StdIn.readLine.toInt
    val as = StdIn.readLine.split(" ").map(_.toInt)

    println(maxPossibleValue(as.foldLeft((0, Int.MaxValue, 0): State)(update)))
  }
}
