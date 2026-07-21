import java.io.{BufferedOutputStream, BufferedReader, InputStreamReader, PrintWriter}
import java.lang

import scala.collection.mutable.ArrayBuffer
import scala.reflect.ClassTag

object Main {
  def get[T: ClassTag](implicit in: BufferedReader, converter: String => T): T = {
    converter(in.readLine)
  }

  def getArray[T: ClassTag](implicit in: BufferedReader, converter: String => T): Array[T] = {
    get[String].split("\\s+").map(converter)
  }

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

  def main(args: Array[String]): Unit = {
    implicit val in: BufferedReader = new BufferedReader(new InputStreamReader(System.in))
    val out = new PrintWriter(new BufferedOutputStream(System.out))
    val Array(r, g, b, n) = getArray[Int]

    var count = 0

    for(rn <- 0 to n) {
      for(gn <- 0 to n) {
        if ((n - rn * r - gn * g) / b >= 0 && (n - rn * r - gn * g) % b == 0) {
          count += 1
        }
      }
    }

    out.println(count)

    out.flush()
  }
}
