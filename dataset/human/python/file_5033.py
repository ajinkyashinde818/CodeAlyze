import scala.collection.mutable

object Main extends App {
  val sc = new java.util.Scanner(System.in)
  val n, m = sc.nextInt

  val fs = mutable.Set.empty[Int]
  val es = mutable.Set.empty[Int]

  (1 to m).foreach { _ =>
    val ai, bi = sc.nextInt
    if (ai == 1) fs.add(bi)
    if (bi == n) es.add(ai)
  }
  println(if ((fs & es).nonEmpty) "POSSIBLE" else "IMPOSSIBLE")
}
