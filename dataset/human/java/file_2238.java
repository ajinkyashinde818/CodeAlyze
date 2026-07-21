import java.io.{BufferedOutputStream, BufferedReader, InputStreamReader, PrintWriter}
import java.lang

import scala.collection.mutable
import scala.collection.mutable.ArrayBuffer
import scala.reflect.ClassTag

object Main {
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

  implicit class TimesInt(val n: Int) {
    def times(f: Int => Unit): Unit = {
      for (i <- 0 until n) {
        f(i)
      }
    }
  }

  def primes(n: Long): ArrayBuffer[Long] = {
    val buf = ArrayBuffer.empty[Long]

    var v = n
    for (i <- 2 to Math.sqrt(n).toInt) {
      if (v == 1 || v == 0) {
        return buf
      } else {
        while (v % i == 0) {
          buf.append(i)
          v /= i
        }
      }
    }
    if (v > Math.sqrt(n).toInt) {
      buf.append(v)
    }
    buf
  }

  def main(args: Array[String]): Unit = {
    implicit val in: BufferedReader = new BufferedReader(new InputStreamReader(System.in))
    val out = new PrintWriter(new BufferedOutputStream(System.out))
    val n = get[Long]

    val primeMap = mutable.HashMap.empty[Long, Int]
    for (p <- primes(n)) {
      val c = primeMap.getOrElse(p, 0)
      primeMap.update(p, c + 1)
    }

    var count = 0L
    for ((p, c) <- primeMap) {
      count += Math.floor((Math.sqrt(8 * c + 1) - 1) / 2).toLong
    }

    out.println(count)
    out.flush()
  }
}
