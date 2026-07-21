import scala.util.control.Breaks._

object Main extends App {
  val Array(n, m) = scala.io.StdIn.readLine().split(' ').map(_.toInt)
  val as = Array.fill(n)(scala.io.StdIn.readLine().toCharArray)
  val bs = Array.fill(m)(scala.io.StdIn.readLine.toCharArray)

  breakable {
    for (hi <- 0 to n - m) {
      for (w <- 0 to n - m) {
        val tmp = (for (h <- 0 until m) yield {
          as(h + hi).slice(w, w + m)
        }).toArray

        if (tmp.corresponds(bs) { _ sameElements _ }) {
          println("Yes")
          break()
        }
      }
    }

    println("No")
  }
}
