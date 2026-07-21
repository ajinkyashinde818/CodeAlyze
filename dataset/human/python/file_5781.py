import scala.io.StdIn
object Main extends App {
  val N = StdIn.readLine().toInt
  val a = StdIn.readLine().split(" ").map(_.toInt).toList
  val b = StdIn.readLine().split(" ").map(_.toInt).toList
  val c = StdIn.readLine().split(" ").map(_.toInt).toList
  val additionalPoints = for {
    i <- 1 to N-1
    if (a(i) - a(i-1) == 1)
  } yield c(a(i-1)-1)
  println(b.sum + additionalPoints.sum)
}
