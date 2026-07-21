object Main{
  def main(args:Array[String]) = {
    val s = scala.io.StdIn.readLine.split("").map(_.toString).sortWith((a,b) => a < b).toList.mkString("")
    val t = scala.io.StdIn.readLine.split("").map(_.toString).sortWith((a,b) => a > b).toList.mkString("")
    if(s < t){
      println("Yes")
    } else {
      println("No")
    }
  }
}
