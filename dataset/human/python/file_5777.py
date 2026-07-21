object Main {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt
    val a = List.fill(n)(sc.nextInt)
    val b = List.fill(n)(sc.nextInt)
    val c = List.fill(n - 1)(sc.nextInt)
    sc.close

    val ans = (0 until n - 1).foldLeft(b.sum)((acc, cur) => {
      if (a(cur) + 1 == a(cur + 1)) acc + c(a(cur) - 1)
      else acc
    })

    println(ans)
  }
}
