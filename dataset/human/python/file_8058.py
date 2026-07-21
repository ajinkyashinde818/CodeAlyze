import scala.io.StdIn


object Main extends App {
  val Array(k, s)  = StdIn.readLine.split(" ").map(_.toInt)

  def solve(k: Int, s: Int) : Int  = {
    var cnt = 0
    for(x <- 0 to k; y <- 0 to k) {
        val z = s - x - y
        if (z >= 0 && z <= k) cnt += 1
    }
    cnt
  }
  println(solve(k, s))

}
