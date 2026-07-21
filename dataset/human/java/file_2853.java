object Main {
  import java.io.{BufferedReader, InputStream, InputStreamReader}
  import java.util.StringTokenizer
  import scala.reflect.ClassTag

  def main(args: Array[String]): Unit = {
    val out = new java.io.PrintWriter(System.out)
    new Main(out, new InputReader(System.in)).solve()
    out.flush()
  }

  private[this] val oj = System.getenv("MY_DEBUG") == null
  def DEBUG(f: => Unit): Unit = {
    if (!oj){ f }
  }
  def debug(as: Array[Boolean]): Unit = if (!oj){ debug(as.map(x => if(x) "1" else "0").mkString) }
  def debug(as: Array[Int]): Unit = if (!oj){ debug(as.mkString(" ")) }
  def debug(as: Array[Long]): Unit =if (!oj){ debug(as.mkString(" ")) }
  def debugDim(m: Array[Array[Int]]): Unit = if (!oj){
    REP(m.length) { i =>
      debug(m(i))
    }
  }
  def debugDimFlip(m: Array[Array[Long]]): Unit = if (!oj){
    REP(m(0).length) { j =>
      REP(m.length) { i =>
        System.err.print(m(i)(j))
        System.err.print(" ")
      }
      System.err.println()
    }
  }
  def debug(s: => String): Unit = {
    if (!oj){ System.err.println(s) }
  }
  def isDebug[A](debug: => A, online: => A): A = {
    if (oj) online else debug
  }

  class InputReader(val stream: InputStream) {
    private[this] val reader = new BufferedReader(new InputStreamReader(stream), 32768)
    private[this] var tokenizer: StringTokenizer = _

    private[this] def next(): String = {
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
    def nm_c(n: Int, m: Int): Array[Array[Char]] = map(n) (_ => ns(m))
  }

  def REP(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = offset
    val N = n + offset
    while(i < N) { f(i); i += 1 }
  }
  def REP_r(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = n - 1 + offset
    while(i >= offset) { f(i); i -= 1 }
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

object Workspace {
  import Main._
  import java.util.Arrays.sort

  import scala.collection.mutable
  import math.{abs, max, min}
  import mutable.ArrayBuffer

  // nCk % MOD を求める。下準備で階乗Fと≡MODでの階乗の逆元Iを作る
  class Comb(N: Int, MOD: Int) {
    def powMod(x: Int, n: Int, m: Int): Int = {
      def step(x: Long, n: Int, stack: Long): Long = {
        n match {
          case 0 => stack
          case _ => step(x * x % m, n / 2, if (n % 2 == 1) stack * x % m else stack)
        }
      }
      step(x, n, 1).toInt
    }

    private[this] val F = Array.ofDim[Long](N + 1)
    F(0) = 1
    REP(N) { i =>
      F(i + 1) = F(i) * (i + 1) % MOD
    }
    private[this] val I = Array.ofDim[Long](F.length)
    I(N) = powMod(F(N).toInt, MOD - 2, MOD)

    // x! = x(x-1)!
    // x!I(x!) ≡ (x-1)!I((x-1)!)
    // I((x-1)!) ≡ I(x!) * x   MODがでかいので(x-1)!はMODと素
    REP_r(N) { i =>
      I(i) = I(i + 1) * (i + 1) % MOD
    }

    def comb(n: Int, k: Int): Long = {
      if (n < k) 0
      else F(n) * I(n - k) % MOD * I(k) % MOD
    }

    def rev(x: Int): Long = {
      I(x) * F(x - 1) % MOD
    }

    /**
      * nのグループからk回重複ありで選ぶ組み合わせ数
      * n - 1のしきりとkの○で考える
      */
    def H(n: Int, k: Int): Long = {
      comb(n + k - 1, k)
    }

    /**
      * private[this]をつかってるのでgetterが必要
      * @return (F, I)
      */
    def get: (Array[Long], Array[Long]) = (F, I)
  }
}

class Main(out: java.io.PrintWriter, sc: Main.InputReader) {
  import sc._
  import Main._
  import java.util.Arrays.sort

  import scala.collection.mutable
  import math.{abs, max, min}
  import mutable.ArrayBuffer
  import Workspace._

  // toIntとか+7とかするならvalにしろ
  final private[this] val MOD = 1000000007

  def solve(): Unit = {
    val N = ni()
    val X = na(N)
    val A = Array.ofDim[Int](N - 1)
    REP(N - 1) { i =>
      A(i) = X(i + 1) - X(i)
    }

    val comb = new Comb(N, MOD)
    val (f, _) = comb.get

    val s = Array.ofDim[Long](N)
    REP(s.length - 1) { i =>
      s(i + 1) = (s(i) + comb.rev(i + 2)) % MOD
    }

    var ans = sumL(A) % MOD * f(N - 1) % MOD
    REP(A.length) { i =>
      val v = A(i) * s(i) % MOD *
        f(N - 1) % MOD
      debug(s"v:$v")
      ans += v
    }
    ans %= MOD
    out.println(ans)
  }
}
