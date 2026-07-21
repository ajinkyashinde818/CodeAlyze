import scala.math.{min,max}
import scala.math.pow
import scala.math.{acos, asin}
import scala.math.sqrt
import scala.math.abs


object Main {
  val sc = new java.util.Scanner(System.in)
  def main(args: Array[String]) {
    while(true) {
      val n = sc.nextInt
      if(n == 0) return

      val w = Array.ofDim[Int](n,3);
      for(i <- 0 until n) {
        for(j <- 0 until 3) {
          w(i)(j) = sc.nextInt
        }
      }

      val m = sc.nextInt
      val ts = Array.ofDim[Int](m, 4)
      for(i <- 0 until m) {
        for(j <- 0 until 4) {
          ts(i)(j) = sc.nextInt
        }
      }
      ts.foreach(tsi => println(test(w, tsi)))
    }
  }
  def test(w: Array[Array[Int]], tsi: Array[Int]) = {
    val eps = 1e-10
    if (w.forall( wi => {
        val d1 = pow(tsi(0) - wi(0),2) + pow(tsi(1) - wi(1),2)
        val d2 = pow(tsi(2) - wi(0),2) + pow(tsi(3) - wi(1),2)
        ( d1 < pow(wi(2), 2) && d2 < pow(wi(2), 2) ) ||
          ( d1 > pow(wi(2), 2) && d2 > pow(wi(2), 2) && !{
            val x = pow(tsi(0) - tsi(2), 2) + pow(tsi(1) - tsi(3), 2)
            x >= d1 - wi(2) * wi(2) && abs(asin(wi(2)/sqrt(d1))) - abs(acos((x + d1 - d2)/(2*sqrt(d1*x)))) > -eps
          })
      })) {
      "Danger"
    } else {
      "Safe"
    }
  }
}
