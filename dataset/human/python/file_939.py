object Main extends App {
  import scala.io.StdIn._
  val g = Array.tabulate(201){_ ⇒ Array.tabulate(101){_ ⇒ -1}}
  g(0)(0) = 0
  for (w ← 0 until 100; b ← 0 until 100) grundy(w, b)
  val state = Array.tabulate(readInt){_ ⇒
    val Array(white, black) = readLine.trim.split(' ').map(_.toInt)
    grundy(white, black)
  }
  println(
    if (state.foldLeft(0){(a, b) ⇒ a ^ b} != 0) 0 else 1
  )
  def grundy(white: Int, black: Int): Int = {//先手必勝ならtrue
    if (g(white)(black) != -1) g(white)(black)
    else if (black == 0) white % 2
    else {
      var all = (1 to math.min(white, black)).reverse.map(remove ⇒ grundy(white, black - remove)).distinct.toList
      if (white > 0) all ::= grundy(white - 1, black)
      if (black > 0) all ::= grundy(white + 1, black - 1)
      val set = all.toSet
      g(white)(black) = (0 until 1000).find(!set.contains(_)).get
      g(white)(black)
    }
  }
}
