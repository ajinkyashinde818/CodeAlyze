object Main extends App {
  val sc = new java.util.Scanner(System.in)
  @scala.annotation.tailrec
  def gcd(x: Long, y: Long): Long = if (y == 0) x else gcd(y, x % y)
  val A, B = sc.nextLong()
  println((A * B) / gcd(A, B))
}
