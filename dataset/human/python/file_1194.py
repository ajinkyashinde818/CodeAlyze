import scala.io.StdIn.readLine

object Main{
  def main(args : Array[String]): Unit ={
    val n : Int = readLine().toInt
    val A : Array[Long] = readLine().split(' ').map(_.toLong)
    def solve(): Long ={
      val sum = A.sum
      var beforeSum : Long = 0
      var res : Long = Long.MaxValue
      for(i <- 0 until n - 1){
        beforeSum += A(i)
        val tmp = math.abs(sum - 2 * beforeSum)
        if(tmp < res) res = tmp
      }
      res
    }
    println(solve())
  }
}
