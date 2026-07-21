object Main {
  def main(args: Array[String]): Unit = {
    import scala.io.StdIn.readLine
    val s2 = readLine.split(" ").head.split("").sorted.mkString
    val t2 = readLine.split(" ").head.split("").sorted.reverse.mkString
    val ans = s2 < t2
    println(if(ans) "Yes" else "No")
  }
}
