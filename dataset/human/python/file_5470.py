import scala.io.StdIn._

object Main {
  def main(args: Array[String]): Unit = {
    val Array(x,y) = readLine.split(" ")
    println(f"${solve(x,y)}")
  }

def solve(a: String, b: String): String = {
  if (a < b) "<"
  else if(a>b) ">"
  else "="
}

}
