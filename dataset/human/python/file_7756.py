object Main {
  def main(args: Array[String]): Unit = {
    solve
  }

  def solve(): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt
    val k = sc.nextInt
    val s = sc.nextLong
    for (i <- 0 until k) {
      print(s + " ")
    }
    val nn = if (s == 1000000000L) s - 1 else s + 1
    for (i <- 0 until n - k) {
      print(nn + " ")
    }
  }

}
