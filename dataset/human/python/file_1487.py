import scala.io.StdIn._

object Main extends App {

  val Array(n,m) = readLine().split(" ").map(_.toInt)
  val A = Array.fill(n)(readLine())
  val B = Array.fill(m)(readLine())

  def solve() = {
    val aLen = A.length
    val bLen = B.length
    val startPoints = for {
      i <- 0 to aLen-bLen
      j <- 0 to aLen-bLen
    } yield (i, j)

    val points = startPoints.map { case (i, j) =>
      for {
        c <- i until i+bLen
        l <- j until j+bLen
      } yield (c, l)
    }

    val isExist = points.exists { list =>
      val listB = for {
        i <- 0 until bLen
        j <- 0 until bLen
      } yield (i, j)
      list.zip(listB).forall { case ((cA,lA), (cB,lB)) =>
        A(cA)(lA) == B(cB)(lB)
      }
    }
    if(isExist) "Yes" else "No"
  }

  println(solve())

}
