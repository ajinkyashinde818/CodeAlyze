object Main {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    val r = sc.nextInt()

    val handicap =
      if (n <= 10) {
        10 - n
      } else {
        0
      }

    val ans = r + (100 * handicap)

    println(ans)
  }
}
