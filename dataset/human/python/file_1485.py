import scala.io.{ StdIn => in}

object Main extends App {
  val Array(n, m) = in.readLine.split(" ").map(_.toInt)
  val a = Iterator.continually(in.readLine.toCharArray)
    .take(n)
    .toArray
  val b = Iterator.continually(in.readLine.toCharArray)
    .take(m)
    .toArray
  val ans = {
    var isExsit = false
    for {
      i <- 0 to n-m
      if !isExsit
      j <- 0 to n-m
      if !isExsit
      } {
        var isCont = true
        for {
          k <- 0 until m
          if isCont
          l <- 0 until m
          if isCont
        } isCont = a(i+k)(j+l) == b(k)(l)

        if(isCont) isExsit = isCont
      }

    if(isExsit) "Yes" else "No"
  }
  println(ans)
}
