object Main extends App {
  val sc = new java.util.Scanner(System.in)
  val n = sc.nextLong()

  def factorize(n: Long): List[Long] = {
    if (n == 1) {
      Nil
    } else {
      var i = 2L
      var d = 0L
      while (i*i <= n && d == 0) {
        if (n % i == 0) d = i
        i += 1
      }
      if (d == 0) List(n) else d::factorize(n/d)
    }
  }

  val factorMap = factorize(n).groupBy(identity).view.mapValues(_.length).toMap
  val counts = factorMap.map{ case (p, k) =>
    var rest = k
    var e = 1
    var ans = 0
    while (e <= rest) {
      ans += 1
      rest -= e
      e += 1
    }
    ans
  }

  println(counts.sum)
}
