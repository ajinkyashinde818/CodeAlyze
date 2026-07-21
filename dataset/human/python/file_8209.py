object Main extends App {
  val sc = new java.util.Scanner(System.in)
  val s = sc.next()
  val x, y = sc.nextInt()

  val d = s.split("T", -1).map(_.length)
  val h = d(0)
  var dx = List[Int]()
  for (i <- 2 until d.length by 2) {
    dx ::= d(i)
  }

  var dy = List[Int]()
  for (i <- 1 until d.length by 2) {
    dy ::= d(i)
  }

  println(if (check(dx.toArray, (x - h).abs) && check(dy.toArray, y.abs)) "Yes" else "No")
  
  def check(a: Array[Int], t: Int): Boolean = {
    def subsetSum(a: Array[Int], n: Int, s: Int): Boolean = {
      val dp = Array.fill(n+1, s+1)(false)
      dp(0)(0) = true
      for {
        i <- 1 to n
        j <- 0 to s
      } {
        if (a(i-1) <= j) {
          dp(i)(j) = dp(i-1)(j) || dp(i-1)(j - a(i-1))
        } else {
          dp(i)(j) = dp(i-1)(j)
        }
      }
      dp(n)(s)
    }

    val sum = a.sum
    !(sum < t || (sum - t) % 2 == 1) && subsetSum(a, a.length, (sum - t) / 2)
  }
}
