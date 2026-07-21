object Main {
  import java.io._
  import java.util.StringTokenizer

  import scala.collection.mutable
  import scala.util.Sorting
  import math.{abs, max, min}
  import mutable.{ArrayBuffer, ListBuffer}
  import scala.reflect.ClassTag

  val MOD = 998244353
  val out = new PrintWriter(System.out)

  def solve(): Unit = {
    val K, N = ni()

    def powMod(x: Int, n: Int, m: Int): Int = {
      def step(x: Long, n: Int, stack: Long): Long = {
        n match {
          case 0 => stack
          case _ => step(x * x % m, n / 2, if (n % 2 == 1) stack * x % m else stack)
        }
      }
      step(x, n, 1).toInt
    }

    val NN = 4000
    val F = Array.ofDim[Long](NN + 1)
    F(0) = 1
    rep(NN) { i =>
      F(i + 1) = F(i) * (i + 1) % MOD
    }
    val I = Array.ofDim[Long](F.length)
    I(NN) = powMod(F(NN).toInt, MOD - 2, MOD)

    // x! = x(x-1)!
    // x!I(x!) ≡ (x-1)!I((x-1)!)
    // I((x-1)!) ≡ I(x!) * x   MODがでかいので(x-1)!はMODと素
    rep_r(NN) { i =>
      I(i) = I(i + 1) * (i + 1) % MOD
    }

    def comb(n: Int, k: Int): Long = {
      if (n < k) 0
      else F(n) * I(n - k) % MOD * I(k) % MOD
    }

    def g(n: Int) = {
      if (n == 0) 1L
      else if (n < 0) 0L
      else comb(n + K - 1, K - 1)
    }

    rep(2 * K - 1, 2) { i =>
      val pairs = min(i / 2, (2 * K - i) / 2 + 1)
      var res = g(N)
      rep(pairs, 1) { j =>
        val sign = (j & 1) == 0
        val x = comb(pairs, j) * g(N - 2 * j) % MOD
        if (sign) res = (res + x) % MOD
        else res = (MOD + res - x) % MOD
      }
      out.println(res)
    }
  }

  def main(args: Array[String]): Unit = {
    solve()
    out.flush()
  }


  class InputReader(val stream: InputStream) {
    private val reader = new BufferedReader(new InputStreamReader(stream), 32768)
    private var tokenizer: StringTokenizer = _

    def next(): String = {
      while (tokenizer == null || !tokenizer.hasMoreTokens)
        tokenizer = new StringTokenizer(reader.readLine)
      tokenizer.nextToken
    }

    def nextInt(): Int = next().toInt
    def nextLong(): Long = next().toLong
    def nextChar(): Char = next().charAt(0)
  }
  val sc = new InputReader(System.in)
  def ni(): Int = sc.nextInt()
  def nl(): Long = sc.nextLong()
  def nc(): Char = sc.nextChar()
  def ns(): String = sc.next()
  def ns(n: Int): Array[Char] = ns().toCharArray
  def na(n: Int): Array[Int] = map(n)(_ => ni())
  def nm(n: Int, m: Int): Array[Array[Char]] = map(n) (_ => ns(m))
  def rep(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = offset
    val N = n + offset
    while(i < N) { f(i); i += 1 }
  }
  def rep_r(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = n - 1 + offset
    while(i >= offset) { f(i); i -= 1 }
  }

  def map[@specialized A: ClassTag](n: Int)(f: Int => A): Array[A] = {
    val res = Array.ofDim[A](n)
    rep(n)(i => res(i) = f(i))
    res
  }

  implicit class ArrayOpts[A](val as: Array[A]) extends AnyVal {
    // todo Orderingだとboxing発生するので自作Orderを用意したい
    def maxByOpt[B: Ordering](f: A => B): Option[A] = {
      if (as.nonEmpty) Some(as.maxBy(f)) else None
    }

    def grpBy[K](f: A => K): mutable.Map[K, ArrayBuffer[A]] = {
      val map = mutable.Map.empty[K, ArrayBuffer[A]]
      rep(as.length)(i => map.getOrElseUpdate(f(as(i)), ArrayBuffer()) += as(i))
      map
    }

    def sumBy[B](f: A => B)(implicit num: Numeric[B]): B = {
      var sum = num.zero
      rep(as.length)(i => sum = num.plus(sum, f(as(i))))
      sum
    }

    def minByEx[B](f: A => B, ixRange: Range = as.indices)(implicit cmp: Ordering[B]): (A, B) = {
      limit(f, ixRange)(cmp.lt)
    }

    def maxByEx[B](f: A => B, ixRange: Range = as.indices)(implicit cmp: Ordering[B]): (A, B) = {
      limit(f, ixRange)(cmp.gt)
    }

    private def limit[B](f: A => B, ixRange: Range)(cmp: (B, B) => Boolean): (A, B) = {
      var limA = as(ixRange.head)
      var limB = f(limA)

      for (i <- ixRange.tail) {
        val a = as(i)
        val b = f(a)
        if (cmp(b, limB)) {
          limA = a
          limB = b
        }
      }
      (limA, limB)
    }
  }

  implicit class IterableOpts[A](val as: Iterable[A]) extends AnyVal {
    def sumBy[B](f: A => B)(implicit num: Numeric[B]): B = {
      as.foldLeft(num.zero)((acc, a) => num.plus(acc, f(a)))
    }
  }
}
