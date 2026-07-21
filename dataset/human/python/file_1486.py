import scala.io.StdIn

object Main extends App {

  val Array(n, m) = StdIn.readLine().split(" ").map(_.toInt)

  val a = (0 until n).map { _ =>
    StdIn.readLine()
  }

  val b = (0 until m).map { _ =>
    StdIn.readLine()
  }

  var im = 0
  var jm = 0
  var judge = false
  for (x <- 0 until n if (x + m) <= n && !judge){ 
    for (y <- 0 until n if (y + m) <= n && !judge) {
      judge = true
      for (z <- 0 until m if (z + m) <= n && judge) {
        //println(a(x + z).substring(y, y + m))
        //println(b(z))
        judge = a(x + z).substring(y, y + m) == b(z)
      }
    }
  }

  println(if (judge) "Yes" else "No")
}
