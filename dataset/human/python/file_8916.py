import scala.io.StdIn
object Main extends App {
  def f(s: List[Char]): Boolean = {
    s match {
      case List('m','a','e','r','d', x @ _*) => f(x.toList)
      case List('r','e','m','a','e','r','d',x @ _*) => f(x.toList)
      case List('e','s','a','r','e',x @ _*) => f(x.toList)
      case List('r','e','s','a','r','e',x @ _*) => f(x.toList)
      case List() => true
      case _ => false
    }
  }
  val S = StdIn.readLine()
  if (f(S.reverse.toList)) println("YES") else println("NO")
}
