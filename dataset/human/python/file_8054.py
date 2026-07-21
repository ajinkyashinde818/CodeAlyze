import scala.io.{ StdIn => in}

object Main extends App {
  val Array(k, s) = in.readLine.split(" ").map(_.toInt)

  val ans = {
    var res = 0
    for(x <- 0 to k; sx = s - x; y <- 0 to k) {
      val z = sx - y
      if(0 <= z && z <= k) res += 1
    }
    res
  }

  println(ans)
}
