object Main {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    val k = sc.nextInt()
    val s = sc.nextInt()
    val nonSValue = if (s == 1) 2 else s - 1
    val nonSLength = n - k

    val ans1 = Array.fill(k)(s)
    val ans2 = Array.fill(nonSLength)(nonSValue)
    val ans = ans1 ++ ans2

    println(ans.mkString(" "))
  }
}
