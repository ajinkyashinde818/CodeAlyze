object Main {
  def main(args: Array[String]): Unit = {
    solve
  }

  def solve(): Unit = {
    val sc = new java.util.Scanner(System.in)
    val n = sc.nextInt()
    val as = new Array[Long](n)
    for (i <- 0 until n) {
      as(i) = sc.nextLong()
    }

    if (as.count(_ < 0) % 2 == 0) {
      // 負の数の個数が偶数の場合、すべての負の符号を反転できる
      val ans = as.foldLeft(0L)((z, v) => z + math.abs(v))
      println(ans)
    } else {
      // 負の数の個数が奇数個の場合、負の数を1つ残して残りの符号を反転できる
      // 残すのは絶対値が最小の数
      val remainedNum = as.foldLeft(Long.MaxValue)((z, v) => if (z > math.abs(v)) math.abs(v) else z)

      // すべての値の絶対値を合算したものから、残った負の数の絶対値 * 2を引く
      val ans = as.foldLeft(0L)((z, v) => z + math.abs(v)) - 2 * remainedNum
      println(ans)
    }
  }
}
