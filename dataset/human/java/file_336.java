import java.io._
import java.util.StringTokenizer

import scala.reflect.ClassTag

object Main {
  def main(args: Array[String]): Unit = {
    try {
      val (in, out) =
        if (isOnlineJudge) {
          (
            new FastScanner(new InputStreamReader(System.in)),
            new PrintWriter(System.out)
          )
        } else {
          (
            new FastScanner(new FileReader(new File("src/resource/problem.in"))),
            new PrintWriter(new File("src/resource/problem.out"))
          )
        }
      new Flipping(in, out).solve()
      out.flush()
      out.close()
    } catch {
      case e: IOException => e.printStackTrace()
    }
  }

  private[this] val isOnlineJudge = true

  class FastScanner(val streamReader: InputStreamReader) {
    private[this] val reader = new BufferedReader(streamReader, 32768)
    private[this] var tokenizer: StringTokenizer = _

    @inline private[this] final def next(): String = {
      while (tokenizer == null || !tokenizer.hasMoreTokens)
        tokenizer = new StringTokenizer(reader.readLine)
      tokenizer.nextToken
    }

    def nextInt(): Int = Integer.parseInt(next())

    def nextLong(): Long = java.lang.Long.parseLong(next())

    def nextChar(): Char = next().charAt(0)

    def ni(): Int = nextInt()

    def nl(): Long = nextLong()

    def nc(): Char = nextChar()

    def ns(): String = next()

    def ns(n: Int): Array[Char] = ns().toCharArray

    def na(n: Int, offset: Int = 0): Array[Int] = map(n)(_ => ni() + offset)

    def na2(n: Int, offset: Int = 0): (Array[Int], Array[Int]) = {
      val A1, A2 = Array.ofDim[Int](n)
      REP(n) { i =>
        A1(i) = ni() + offset
        A2(i) = ni() + offset
      }
      (A1, A2)
    }

    def nm(n: Int, m: Int): Array[Array[Int]] = {
      val A = Array.ofDim[Int](n, m)
      REP(n) { i =>
        REP(m) { j =>
          A(i)(j) = ni()
        }
      }
      A
    }

    def nal(n: Int): Array[Long] = map(n)(_ => nl())

    def nm_c(n: Int, m: Int): Array[Array[Char]] = map(n)(_ => ns(m))
  }

  def REP(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = offset
    val N = n + offset
    while (i < N) {
      f(i);
      i += 1
    }
  }

  def REP_r(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = n - 1 + offset
    while (i >= offset) {
      f(i);
      i -= 1
    }
  }

  def TO(from: Int, to: Int)(f: Int => Unit): Unit = {
    REP(to - from + 1, from)(f)
  }

  def map[@specialized A: ClassTag](n: Int, offset: Int = 0)(f: Int => A): Array[A] = {
    val res = Array.ofDim[A](n)
    REP(n)(i => res(i) = f(i + offset))
    res
  }

  def sumL(as: Array[Int]): Long = {
    var s = 0L
    REP(as.length)(i => s += as(i))
    s
  }

  def cumSum(as: Array[Int]): Array[Long] = {
    val cum = Array.ofDim[Long](as.length + 1)
    REP(as.length) { i =>
      cum(i + 1) = cum(i) + as(i)
    }
    cum
  }
}

class Flipping(fScanner: Main.FastScanner, out: java.io.PrintWriter) {

  import Main._
  import fScanner._

  def solve(): Unit = {
    val N = ni()
    val A = na(N)
    val dp = Array.ofDim[Long](N+1, 2)
    dp(0)(0) = 0
    dp(0)(1) = Integer.MIN_VALUE

    REP(N) { i =>
      dp(i+1)(0) = Math.max(dp(i)(0) + A(i), dp(i)(1) - A(i))
      dp(i+1)(1) = Math.max(dp(i)(1) + A(i), dp(i)(0) - A(i))
    }
    out.println(dp(N)(0))
  }
}
