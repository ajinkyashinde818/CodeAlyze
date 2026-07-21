import java.io.{BufferedOutputStream, BufferedReader, InputStreamReader, PrintWriter}
import java.lang

import scala.annotation.tailrec
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

  def main(args: Array[String]): Unit = {
    implicit val in: BufferedReader = new BufferedReader(new InputStreamReader(System.in))
    val out = new PrintWriter(new BufferedOutputStream(System.out))
    val s = get[String]

    @tailrec
    def count(l: Int, r: Int, c: Int): Int = {
      if (r <= l) {
        c
      } else {
        if (s(l) == s(r)) {
          count(l + 1, r - 1, c)
        } else if (s(l) == 'x') {
          count(l + 1, r, c + 1)
        } else if (s(r) == 'x') {
          count(l, r - 1, c + 1)
        } else {
          -1
        }
      }
    }

    out.println(count(0, s.length - 1, 0))

    out.flush()
  }
}
