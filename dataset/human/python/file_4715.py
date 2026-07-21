object Main extends App {
  val inputs: Seq[String] = scala.io.Source.stdin.getLines().toList
  val s = inputs(0)
  val t = inputs(1)

  println(solve(s, t))

  def solve(s: String, t: String): String = {
    val sortedS = s.sorted
    val sortedT = t.sorted.reverse

    if(sortedS < sortedT) {
      "Yes"
    } else {
      "No"
    }
  }
}
