object Main extends App {
  val sc = new java.util.Scanner(System.in)
  var a, b = sc.nextLong

  val ans = lcm(a, b)
  println(ans)

  def gcd(x: Long, y: Long): Long = {
    if (y == 0) x
    else gcd(y, x % y)
  }

  def lcm(x: Long, y: Long): Long = {
    if (x == 0 || y == 0) 0
    else (x * y / gcd(x, y))
  }
}
