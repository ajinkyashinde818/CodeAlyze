object Main extends App {
  import scala.math.{min,max}
  def g(a:Long,b:Long):Long = {
    val x = min(a,b)
    val y = max(a,b)
    if (x == 0) y
    else g(x,y%x)
  }
  
  val Array(a,b) = readLine.split(" ").map{_.toLong}
  val gg = g(a,b)
  val Array(aa,bb) = Array(a/gg,b/gg)
  println(gg*aa*bb)
}
