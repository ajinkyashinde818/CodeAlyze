object Main extends App {
  import scala.io.StdIn._
  val Array(k,n) = readLine().split(" ").map(_.toInt)
  val a = readLine().split(" ").map(_.toInt)
  var long = k - a(n-1) + a(0)
  for (i <- (0 until(n-1))){
    long = Math.max(long,a(i + 1) - a(i))
  }
  println(k - long)
}
