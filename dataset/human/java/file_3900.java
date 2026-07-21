import java.io._
import java.util.StringTokenizer

import scala.collection.mutable
import scala.util.Sorting
import math.{abs, max, min}
import scala.collection.mutable.{ArrayBuffer, ListBuffer}
import scala.reflect.ClassTag

object Main {
  val MOD = 1000000007
  val out = new PrintWriter(System.out)

  def solve(): Unit = {
    val sc = new InputReader(System.in)
    val S1 = sc.next()
    val S2 = S1.reverse
    val S = S1 filterNot (_ == 'x')
    val N = S1.length
    val M = S.length
    val ok = (0 until M / 2) forall { i =>
      S(i) == S(M - 1 - i)
    }

    def countXs(n: Int, S: String): Array[Int] = {
      val xs = Array.ofDim[Int](n)
      def step(i: Int, j: Int, k: Int): Unit = {
        if (i == n) ()
        else if (j == N) xs(i) = k
        else {
          S(j) match {
            case 'x' => step(i, j + 1, k + 1)
            case _ =>
              xs(i) = k
              step(i + 1, j + 1, 0)
          }
        }
      }
      step(0, 0, 0)
      xs
    }

    val ans = if (!ok) -1 else {
      val n = (M + 1) / 2
      val L = countXs(n, S1)
      val R = countXs(n, S2)
      map(n)(identity).sumBy(i => abs(L(i) - R(i)))
    }

    out.println(ans)
  }

  def main(args: Array[String]): Unit = {
    solve()
    out.flush()
  }


  class InputReader(val stream: InputStream) {
    private val reader = new BufferedReader(new InputStreamReader(stream), 32768)
    private var tokenizer: StringTokenizer = null

    def next(): String = {
      while (tokenizer == null || !tokenizer.hasMoreTokens)
        tokenizer = new StringTokenizer(reader.readLine)
      tokenizer.nextToken
    }

    def nextInt(): Int = next().toInt
    def nextLong(): Long = next().toLong
    def nextChar(): Char = next().charAt(0)
  }
  def rep(n: Int)(f: Int => Unit): Unit = {
    var i = 0
    while(i < n) { f(i); i += 1 }
  }
  def rep_r(n: Int)(f: Int => Unit): Unit = {
    var i = n - 1
    while(i >= 0) { f(i); i -= 1 }
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
