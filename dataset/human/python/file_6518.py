import scala.io.StdIn._

object Main extends App {

  val s = readLine()
  val qNum = readInt()
  val Q = Array.fill(qNum)(readLine().split(" "))

  def solve() = {
    val chrSeq = s.toVector
    val (chars, reverseCnt) = Q.foldLeft((chrSeq, 0)) { case ((acc, reverseCnt), q) =>
      if(q.length == 1) (acc, reverseCnt+1)
      else (f(q(2).head, acc, reverseCnt, q(1)), reverseCnt)
    }
    if(reverseCnt % 2 == 0) chars.mkString("") else chars.reverse.mkString("")
  }

  def f(chr: Char, chrSeq: Vector[Char], reverseCnt: Int, direction: String): Vector[Char] = {
    val isHead = direction == "1"
    if(reverseCnt % 2 == 0)
      if(isHead) chr +: chrSeq else chrSeq :+ chr
    else
      if(isHead) chrSeq :+ chr else chr +: chrSeq
  }

  println(solve())

}
