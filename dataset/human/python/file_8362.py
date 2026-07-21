import scala.io.StdIn._

object Main extends App {

  val Array(k, n) = readLine.split(" ").map(_.toInt)

  val points = readLine.split(" ").map(_.toInt)

  val distances = points.zipWithIndex.map { case (pos, idx) =>
      if (idx == 0) (k - points(points.length - 1)) + pos
      else pos - points(idx - 1)
  }

  val maxDis = distances.zipWithIndex.maxBy { case (dis, _) => dis }._1

  println(k - maxDis)
}
