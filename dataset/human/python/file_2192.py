object Main {
  import io.StdIn._

  def getStrings = readLine().split(" ")
  def getInts = getStrings.map(_.toInt)

  def main(args: Array[String]): Unit = {
    val Array(d, g) = getInts

    val exercises = {
      for (_ <- 1 to d) yield {
        val Array(p, c) = getInts
        (p, c)
      }
    }

    val minSolveNumbers = for (bits <- 0 until 1 << d) yield {
      val allSolveList: Seq[Int] = for (digit <- 0 until d if (bits & (1 << digit)) != 0) yield digit
      val pointSum = allSolveList.map(i => (i + 1) * 100 * exercises(i)._1 + exercises(i)._2).sum
      if (pointSum < g) {
        val highestRemaining = (0 until d).filter(!allSolveList.contains(_)).max
        val required = ((g - pointSum) / (100.0 * (highestRemaining + 1))).ceil.toInt
        if (required < exercises(highestRemaining)._1) {
          Some(allSolveList.map(exercises(_)._1).sum + required)
        } else {
          None
        }
      } else {
        Some(allSolveList.map(exercises(_)._1).sum)
      }
    }
    println(minSolveNumbers.flatten.min)
  }
}
