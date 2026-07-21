object Main {
  def main(args: Array[String]): Unit = {
    solve
  }

  def solve(): Unit = {
    val sc = new java.util.Scanner(System.in)
    val d, g = sc.nextInt
    val p = new Array[Int](d)
    val c = new Array[Int](d)
    for (i <- 0 until d) {
      p(i) = sc.nextInt
      c(i) = sc.nextInt
    }

    // ボーナスを獲得できる/できないで全パターン探索
    var ans = Int.MaxValue
    for (mask <- 0 until (1 << d)) {
      // D問のビットパターン
      var s = 0
      var num = 0
      var restMax = -1

      for (i <- 0 until d) {
        if (((mask >> i) & 1) == 1) {
          // ボーナス獲得問題！
          // 通常問題の点数 + ボーナス点数
          s += 100 * (i + 1) * p(i) + c(i)
          // 解答した問題数
          num += p(i)
        } else {
          restMax = i
        }
      }

      var flg = true
      if (s < g) {
        // ボーナスを獲得していない問題のうち点数が最大の問題の点数
        val s1 = 100 * (restMax + 1)
        // 残り何問解答すればよいか
        val need = (g - s + s1 - 1) / s1
        if (need >= p(restMax)) {
          // 当該問題でまかなえない（=残りの点数に足りない）ことで、全問回答する場合は、
          // 別のビットパターンで対象となる！
          flg = false
        } else {
          num += need
        }

      }
      if (flg) {
        ans = math.min(ans, num)
      }
    }

    println(ans)
  }
}
