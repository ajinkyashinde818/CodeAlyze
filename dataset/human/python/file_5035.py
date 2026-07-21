import scala.collection.mutable.ArrayBuffer

object Main {
  def main(args: Array[String]): Unit = {
    solve2
  }

  def solve2(): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n, m = sc.nextInt
    val firstCon = scala.collection.mutable.Set[Int]()
    val lastCon = scala.collection.mutable.Set[Int]()
    val con = Array.fill[ArrayBuffer[Int]](n)(new ArrayBuffer[Int]())
    for (i <- 0 until m) {
      val a = sc.nextInt
      val b = sc.nextInt

      if (a == 1) firstCon += b
      if (b == n) lastCon += a
    }

    println(if ((firstCon & lastCon).nonEmpty) "POSSIBLE" else "IMPOSSIBLE")

  }


  def solve(): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n, m = sc.nextInt
    val con = Array.fill[ArrayBuffer[Int]](n)(new ArrayBuffer[Int]())
    for (i <- 0 until m) {
      val a = sc.nextInt - 1
      val b = sc.nextInt - 1
      con(a).append(b)
      con(b).append(a)
    }

    val destNum = n - 1
    var ans = false
    for (num <- con(0)) {
      if (con(num).contains(destNum)) {
        ans = true
      }
    }

    println(if (ans) "POSSIBLE" else "IMPOSSIBLE")

  }
}
