object Main extends App {
  val sc = new java.util.Scanner(System.in)
  val n = sc.nextLong
  
  def loop(m: Long, count: Long): Long = {
    if (m < 10) count
    else loop(m / 5, count + m / 10)
  }
  
  println(if (n % 2 == 1) 0 else loop(n, 0))
}
