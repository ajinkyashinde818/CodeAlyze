import scala.collection.mutable
import scala.util.Random

object Main {

  val r = new Random()

  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val N = sc.nextInt()
    val map = new mutable.HashMap[Char, Int]
    for {
      x <- 'a' to 'z'
    } {
      map(x) = 0
    }


    val S = sc.next()
    for {
      s <- S
    } {
      map(s) = map(s) + 1
    }

    println(map.foldLeft(1L) {
      (acc, x) => (acc * (x._2 + 1)) % 1000000007
    } - 1)
  }
}
