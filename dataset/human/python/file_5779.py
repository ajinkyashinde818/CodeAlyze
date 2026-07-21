import scala.io.StdIn

object Main extends App {
  val n  = StdIn.readLine().toInt
  val a :Array[Int] = StdIn.readLine().split(" ").map(_.toInt)
  val b :Array[Int] = StdIn.readLine().split(" ").map(_.toInt)
  val c :Array[Int] = StdIn.readLine().split(" ").map(_.toInt)  
  var ans = 0
  var prev = a(0)

  (0 to a.length - 1).foreach {i =>
    val position = a(i) - 1
    ans = ans + b(position)

    if (prev == position - 1) ans = ans + c(prev)

    prev = position
  }

  println(ans)
}
