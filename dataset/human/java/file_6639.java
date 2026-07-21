import java.io._
import java.util
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
    val S = sc.next()
    val x, y = sc.nextInt()

    val X, Y = ArrayBuffer[Int]()
    var h = true
    var move = 0
    rep(S.length) { i =>
      S(i) match {
        case 'F' => move += 1
        case 'T' =>
          (if (h) X else Y) += move
          h ^= true
          move = 0
      }
    }
    if (move > 0) (if (h) X else Y) += move

    def reach(A: ArrayBuffer[Int], t: Int): Boolean = {
      val sum = A.sum
      if (abs(t) > sum) false // 移動距離が足りない
      else {
        var cur, next = Array.ofDim[Boolean](sum * 2 + 1)
        cur(sum) = true
        rep(A.length) { i =>
          rep(sum * 2 + 1) { j =>
            if (j + A(i) <= sum * 2) next(j) ||= cur(j + A(i))
            if (j - A(i) >= 0) next(j) ||= cur(j - A(i))
          }
          val tmp = cur
          cur = next
          next = tmp
          util.Arrays.fill(next, false)
        }
        cur(sum + t)
      }
    }

    val ok = reach(X.drop(1), x - X(0)) && reach(Y, y)
    val ans = if (ok) "Yes" else "No"
    out.println(ans)
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
