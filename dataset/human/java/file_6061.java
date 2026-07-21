import java.io.{BufferedReader, InputStream, InputStreamReader}
import java.util.StringTokenizer

import scala.collection.mutable
import scala.util.Sorting
import math.{abs, max, min}

object Main {
  val MOD = 1000000007
  def solve(): Unit = {
    val sc = new InputReader(System.in)
    val N = sc.nextInt()
    val a = Array.fill[Int](N)(sc.nextInt())
    val b = Array.fill[Int](N)(sc.nextInt())
    val b1 = Array.ofDim[Int](N)

    def modArray(src: Array[Int], dist: Array[Int], m: Int)= {
      src.indices foreach { i =>
        dist(i) = src(i) % m
      }
    }

    var ans = 0
    (0 to 28) foreach { k =>
      val T = 1 << k
      modArray(b, b1, 2 * T)
      Sorting.quickSort(b1)
      var sum: Long = 0
      a.indices foreach { i =>
        val a1 = a(i) % (2 * T)
        // lowerBoundは b < x を満たすbの数
        val lb1 = lowerBound(b1, T - a1)
        val lb2 = lowerBound(b1, 2 * T - a1)
        val lb3 = lowerBound(b1, 3 * T - a1)
        val lb4 = N
        sum += lb2 - lb1 + lb4 - lb3
      }

      if (sum % 2 == 1) ans += T
    }

    println(ans)
  }


  def main(args: Array[String]): Unit = {
    solve()
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

  def lowerBound(a: Array[Int], x: Int): Int = {
    def step(l: Int, h: Int): Int = {
      if (h - l == 1) h
      else {
        val mid = l + (h - l) / 2
        if (a(mid) >= x) step(l, mid)
        else step(mid, h)
      }
    }
    step(-1, a.length)
  }
}
