object Main {
  def main(args: Array[String]): Unit = {
    solve
  }

  def solve(): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt
    val a = new Array[Long](n)
    for (i <- 0 until n) {
      a(i) = sc.nextLong()
    }

    val acc = a.scanLeft(0L)(_ + _)
    var ans = Long.MaxValue
    for (i <- 1 until n) {
      val x = acc(i)
      val y = acc(n) - acc(i)
      ans = math.min(ans, math.abs(x - y))
    }
    println(ans)
  }
}
