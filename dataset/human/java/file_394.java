import java.awt.geom.Point2D
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

  case class Barrier(x: Int, y: Int, r: Int)
  type WUGraph = Array[Barrier]
  case class Coordinate(x: Int, y: Int)

  def solve(): Unit = {
    val sc = new InputReader(System.in)
    val xs, ys, xt, yt, N = sc.nextInt()
    val g = Array.ofDim[Barrier](N + 2)
    g(0) = Barrier(xs, ys, 0)
    g(N + 1) = Barrier(xt, yt, 0)
    rep(N) { i =>
      val x, y, r = sc.nextInt()
      g(i + 1) = Barrier(x, y, r)
    }

    val ans = dijk(g, 0, N + 1) { (v, i) =>
      val u = if (i < v) i else i + 1
      val d = Point2D.distance(g(v).x, g(v).y, g(u).x, g(u).y) - g(v).r - g(u).r
      Edge(u, max(d, 0))
    }

    println(f"$ans%.15f")
  }


  def main(args: Array[String]): Unit = {
    solve()
    out.flush()
  }


  class InputReader(val stream: InputStream) {
    private val reader = new BufferedReader(new InputStreamReader(stream), 32768)
    private var tokenizer: StringTokenizer = null

    def next: String = {
      while (tokenizer == null || !tokenizer.hasMoreTokens)
        tokenizer = new StringTokenizer(reader.readLine)
      tokenizer.nextToken
    }

    def nextInt(): Int = next.toInt
    def nextLong(): Long = next.toLong
    def nextChar(): Char = next.charAt(0)
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

  case class Edge(to: Int, weight: Double)

  def dijk(g: WUGraph, start: Int, end: Int)(edge: (Int, Int) => Edge): Double = {
    val d = Array.fill[Double](g.length)(Double.PositiveInfinity)
    case class Visit(node: Int, cost: Double) extends Comparable[Visit] {
      override def compareTo(o: Visit): Int = java.lang.Double.compare(cost, o.cost)
    }
    val queue = new java.util.PriorityQueue[Visit]()
    d(start) = 0
    queue.add(Visit(start, 0))

    while(!queue.isEmpty) {
      val v = queue.poll()
      if (d(v.node) == v.cost) {
        val len = g.length - 1 //  v以外のノードと連結している
        rep(len) { i =>
          val e = edge(v.node, i)
          val next = v.cost + e.weight
          if (d(e.to) > next) {
            d(e.to) = next
            queue.add(Visit(e.to, next))
          }
        }
      }
    }

    d(end)
  }
}
