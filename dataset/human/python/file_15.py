object Main {

    def main(args: Array[String]): Unit = {
      import scala.io.StdIn._
      val Array(r, g, b, n) = readLine().split(" ").map(_.toInt)

      val rMax = n / r
      var c = 0
      for {
        i <- 0 to rMax
        rR = r * i
        gMax = (n - rR) / g
        j <- 0 to gMax
        gG = g * j
        if (n - rR - gG) % b == 0
      } c += 1

      println(c)
    }

}
