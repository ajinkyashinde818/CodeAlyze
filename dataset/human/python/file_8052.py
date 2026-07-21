import scala.io.StdIn

object Main extends App {

  val Array(k, s) = StdIn.readLine().split(" ").map(_.toInt)

  var count = 0
  for (x <- 0 to k; y <- 0 to k)
    yield count += (if (0 <= s - (x + y) && s - (x + y) <= k) 1 else 0)

  println(count)

}
