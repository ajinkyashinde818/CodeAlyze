object Main extends App {
  val in = new java.util.Scanner(System.in)
  val N = in.nextLong

  val divs = 0 +: (1 to 10).flatMap(i => Array.fill(i + 1)(i))

  def div(n: Long, p: Long, c: Int): Int = {
    if (n == 1L) c
    else if (p * p > n) c + 1
    else {
      def divCount(n0: Long, c0: Int): (Long, Int) = if (n0 % p == 0) divCount(n0 / p, c0 + 1) else (n0, c0)
      val (n0, c0) = divCount(n, 0)
      div(n0, p + 1, c + divs(c0))
    }
  }

  println(div(N, 2L, 0))
}
