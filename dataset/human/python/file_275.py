object Main {

  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)

    val N = sc.nextInt()
    val A = Array.fill(N)(sc.nextInt())
    val isEven = A.count(_ < 0) % 2 == 0

    val absSum = A.map(a => Math.abs(a)).foldLeft(0L)(_ + _)

    val res =
      if (isEven) absSum
      else absSum - (2 * A.map(a => Math.abs(a)).min)
    println(res)
  }

}
