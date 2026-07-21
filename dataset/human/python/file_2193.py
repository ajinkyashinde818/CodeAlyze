object Main extends App {
  import scala.util.control.Breaks._
  val Array(d, g) = io.StdIn.readLine().split(' ').map(_.toInt)
  val (p, c) = Array.fill(d){
    val Array(pi, ci) = io.StdIn.readLine().split(' ').map(_.toInt)
    (pi, ci)
  }.unzip
  var min = p.sum
  for (b <- 0 until 1 << d) {
    val indices = for (i <- 0 to d; if (b >> i & 1) == 1) yield i
    var sum = 0
    val count = Array.fill(d)(0)
    indices.foreach {i =>
      sum += 100 * (i+1) * p(i) + c(i)
      count(i) = p(i)
    }
    breakable {
      for (i <- d-1 to 0 by -1)
        while (count(i) < p(i)) {
          if (sum >= g) break
          sum += 100 * (i+1)
          count(i) += 1
          if (count(i) == p(i)) sum += c(i)
        }
    }
    if (count.sum < min) min = count.sum
  }
  println(min)
}
