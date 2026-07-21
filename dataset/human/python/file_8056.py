import scala.io.StdIn
object Main extends App {
  val List(k, s) = StdIn.readLine().split(" ").map(_.toInt).toList
  var cnt = 0
  for {
    x <- 0 to k
    y <- 0 to k
    z = s - x - y
    if (0 <= z && z <= k)
  } cnt += 1;
  println(cnt)
}
