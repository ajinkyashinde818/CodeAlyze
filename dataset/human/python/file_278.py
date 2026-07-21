import scala.math._

object Main {
  def main(args: Array[String]): Unit = {
    val lines = io.Source.stdin.getLines().toSeq
    println(solve(lines))
  }

  def solve(lines: Seq[String]): String = {
    val n = lines.head.toInt // N
    val nums = lines.tail.head.split(" ").map(_.toLong).toSeq
    debug(n, nums)

    val minusNumsCount = nums.count(_ < 0)
    val result = if (minusNumsCount % 2 == 0) nums.map(abs).sum else nums.map(abs).sum - nums.map(abs).min * 2
    result.toString
  }

  private def debug(x: Any): Unit = {
    if (System.getenv("LOCAL_DEBUG") != null)
      println(x)
  }
}
