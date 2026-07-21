object Main {

  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val N = sc.nextInt()
    val A = Array.fill[Long](N)(sc.nextLong)
    val result = if (A.count(_.<(0)) % 2 == 0) {
      A.map(Math.abs).sum
    } else {
      val absA = A.map(Math.abs)
      absA.sum - 2 * absA.min
    }

    println(result)
  }
}
