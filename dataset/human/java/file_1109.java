import java.io.{BufferedOutputStream, BufferedReader, FileOutputStream, InputStreamReader, PrintWriter}
import java.lang

import scala.annotation.tailrec
import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer
import scala.reflect.ClassTag

object Main {
  val DEBUG = false

  lazy val debugOut: PrintWriter = {
    new PrintWriter(new BufferedOutputStream(new FileOutputStream("log.txt", true)))
  }

  def log(message: => String): Unit = {
    if (DEBUG) {
      debugOut.println(message)
    }
  }

  def debug(closure: => Unit): Unit = {
    if (DEBUG) {
      closure
    }
  }

  def get[T: ClassTag](implicit in: BufferedReader, converter: String => T): T = {
    converter(in.readLine)
  }

  def getArray[T: ClassTag](implicit in: BufferedReader, converter: String => T): Array[T] = {
    get[String].split("\\s+").map[T](converter)
  }

  implicit val idConverter: String => String = s => s
  implicit val intConverter: String => Int = s => Integer.parseInt(s)
  implicit val longConverter: String => Long = s => lang.Long.parseLong(s)

  def get[T1, T2](
                   implicit in: BufferedReader,
                   converter1: String => T1,
                   converter2: String => T2
                 ): (T1, T2) = {
    getArray[String] match {
      case Array(v1, v2) => (converter1(v1), converter2(v2))
    }
  }

  def get[T1, T2, T3](
                       implicit in: BufferedReader,
                       converter1: String => T1,
                       converter2: String => T2,
                       converter3: String => T3
                     ): (T1, T2, T3) = {
    getArray[String] match {
      case Array(v1, v2, v3) => (converter1(v1), converter2(v2), converter3(v3))
    }
  }

  def get[T1, T2, T3, T4](
                           implicit in: BufferedReader,
                           converter1: String => T1,
                           converter2: String => T2,
                           converter3: String => T3,
                           converter4: String => T4
                         ): (T1, T2, T3, T4) = {
    getArray[String] match {
      case Array(v1, v2, v3, v4) => (converter1(v1), converter2(v2), converter3(v3), converter4(v4))
    }
  }

  implicit class TimesInt(val n: Int) {
    def times(f: Int => Unit): Unit = {
      for (i <- 0 until n) {
        f(i)
      }
    }
  }

  def primes(n: Long): ArrayBuffer[Long] = {
    val buf = ArrayBuffer.empty[Long]
    val s = Math.sqrt(n).toInt

    var v = n
    for (i <- 2 to s) {
      if (v == 1 || v == 0) {
        return buf
      } else {
        while (v % i == 0) {
          buf.append(i)
          v /= i
        }
      }
    }
    if (v > s) {
      buf.append(v)
    }
    buf
  }

  def divisors(n: Int): ArrayBuffer[Int] = {
    val buf = ArrayBuffer.empty[Int]
    val s = Math.sqrt(n).toInt

    for (i <- 1 to s) {
      if (n % i == 0) {
        buf.append(i)
        if (i != n / i) {
          buf.append(n / i)
        }
      }
    }
    buf
  }

  @tailrec
  def gcd(a: Long, b: Long): Long = {
    val reminder = a % b
    if (reminder == 0) {
      b
    } else {
      gcd(b, reminder)
    }
  }

  @tailrec
  def gcd(a: Int, b: Int): Int = {
    val reminder = a % b
    if (reminder == 0) {
      b
    } else {
      gcd(b, reminder)
    }
  }

  def lcm(a: Long, b: Long): Long = {
    a / gcd(a, b) * b
  }

  def toBitArray(n: Int, width: Int): Array[Boolean] = {
    val buf = ArrayBuffer.fill(width)(false)

    @tailrec
    def inner(n: Int, i: Int): Array[Boolean] = {
      buf(i) = (n & 1) == 0
      if (i == 0) {
        buf.toArray
      } else {
        inner(n / 2, i - 1)
      }
    }

    inner(n, width - 1)
  }

  def modpow(n: Long, p: Long, m: Long): Long = {
    @tailrec
    def inner(n: Long, p: Long, acc: Long): Long = {
      if (p == 0) {
        acc
      } else if ((p & 1) == 0) {
        inner(n * n % m, p >> 1, acc)
      } else {
        inner(n * n % m, p >> 1, acc * n % m)
      }
    }

    inner(n % m, p, 1)
  }

  def main(args: Array[String]): Unit = {
    implicit val in: BufferedReader = new BufferedReader(new InputStreamReader(System.in))
    val out = new PrintWriter(new BufferedOutputStream(System.out))

    log("=== start")

    val n = get[Int]
    val as = getArray[Int]
    val bs = getArray[Int]

    def swap(i: Int, j: Int): Unit = {
      val t = bs(j)
      bs(j) = bs(i)
      bs(i) = t
    }

    @tailrec
    def reallocate(i: Int, previousA: Int, previousJ: Int): Boolean = {
      if (i == n) {
        true
      } else {
        val j = if (as(i) == previousA) {
          previousJ
        } else {
          0
        }

        if (as(i) != bs(i)) {
          reallocate(i + 1, as(i), j)
        } else {
          @tailrec
          def find(j: Int): Int = {
            if (j == n) {
              n
            } else if (as(i) != as(j) && as(i) != bs(j)) {
              j
            } else {
              find(j + 1)
            }
          }

          find(j) match {
            case `n` =>
              false
            case j =>
              swap(i, j)
              reallocate(i + 1, as(i), j)
          }
        }
      }
    }

    if (reallocate(0, -1, -1)) {
      out.println("Yes")
      out.println(bs.mkString(" "))
    } else {
      out.println("No")
    }

    out.flush()
    log("=== end")
    debug {
      debugOut.flush()
    }
  }

}
