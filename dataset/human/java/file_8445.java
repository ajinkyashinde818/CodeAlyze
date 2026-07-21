object Main {
  def main(args: Array[String]): Unit = {
    val s = new Main()
    s.solve()
    s.out.flush()
  }
}

class Main {
  import java.io._
  import java.util.StringTokenizer

  import scala.collection.mutable
  import scala.util.Sorting
  import math.{abs, max, min}
  import mutable.{ArrayBuffer, ListBuffer}
  import scala.reflect.ClassTag

  val MOD = 1000000007
  val out = new PrintWriter(System.out)

  /**
    * [from, to]
    */
  case class Node(v: Int, from: Int, to: Int)

  class PrefixTree(maxDepth: Int, width: Int) {
    val nodes = Array.ofDim[Node](maxDepth)
    val hasSibs = Array.ofDim[Int](maxDepth) // 深さで管理
    var p = 0
    var q = 0
    var len = 0

    def truncate(depth: Int): Unit = {
      p = upperBound(nodes, depth, p)(_.from)
      if (p > 0 && nodes(p-1).to > depth) {
        val n = nodes(p-1)
        nodes(p-1) = Node(n.v, n.from, depth)
      }
      q = upperBound(hasSibs, depth, q)(identity)
      len = depth
    }

    def next(): Boolean = {
      if (q == 0) false
      else {
        val target = hasSibs(q-1) // ラスト
        val old = get(target)
        val parentDepth = old.to - 1 // oldノードの一番下を入れ替えたい
        truncate(parentDepth)
        fill(old.v + 1, parentDepth + 1)
        true
      }
    }

    def fill(v: Int, depth: Int): Unit = {
      nodes(p) = Node(v, length + 1, depth)
      p += 1

      if (v < width) {
        hasSibs(q) = length + 1
        q += 1
      }
      len = depth
    }

    def get(depth: Int): Node = {
      val ix = upperBound(nodes, depth, p)(_.from) - 1
      assert(ix >= 0)
      nodes(ix)
    }

    def length: Int = len
  }

  def solve(): Unit = {
    val N = ni()
    val A = na(N)

    def ok(x: Int): Boolean = {
      val t = new PrefixTree(N, x)

      REP(N) { i =>
        if (A(i) > t.length) {
          t.fill(1, A(i))
        } else {
          t.truncate(A(i))
          if (!t.next()) return false
        }
      }

      true
    }

    var l = 0
    var r = N
    while(r - l > 1) {
      val m = (r + l) / 2
      if (ok(m)) r = m
      else l = m
    }

    out.println(r)
  }

  // 要はcountLe
  // a > x  [x-2, x-1, x, x, x, x+1] の 5
  def upperBound[@specialized A](a: Array[A], x: Int, mx: Int)(f: A => Int): Int = {
    def step(l: Int, h: Int): Int = {
      if (h - l == 1) h
      else {
        val mid = (l + h) / 2
        if (f(a(mid)) > x) step(l, mid)
        else step(mid, h)
      }
    }

    step(-1, mx)
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
  def REP(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = offset
    val N = n + offset
    while(i < N) { f(i); i += 1 }
  }
  def REP_r(n: Int, offset: Int = 0)(f: Int => Unit): Unit = {
    var i = n - 1 + offset
    while(i >= offset) { f(i); i -= 1 }
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

  def cumSum(as: Array[Int]) = {
    val cum = Array.ofDim[Long](as.length + 1)
    REP(as.length) { i =>
      cum(i + 1) = cum(i) + as(i)
    }
    cum
  }
}
