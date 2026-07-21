import scala.io.StdIn._
object Main extends App{
  val sc = new java.util.Scanner(System.in)
  var s = sc.next
  if(s.contains("a")&&s.contains("b")&&s.contains("c")){
    println("Yes")
  }
  else{
    println("No")
  }
}
