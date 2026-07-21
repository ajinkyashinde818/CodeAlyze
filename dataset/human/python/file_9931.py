object Main extends App {
  val sc = new java.util.Scanner(System.in)
  val a,b = sc.nextLong
  
  def loop(p: Long, q: Long): Long = {
    val r = p % q
    if (r == 0) q
    else loop(q, r)
  }
  
  val koyakusu = if (a >= b) loop(a, b) else loop(b, a)
  
  println(a * b / loop(a, b))
}
