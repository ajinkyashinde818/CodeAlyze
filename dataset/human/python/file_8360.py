object Main extends App {
  import scala.io.StdIn.readLine
  
  	val k = readLine.split(" ").head.toInt;
  	val homes =readLine.split(" ").map(_.toInt).toList;
  	println((k - (homes zip (homes.tail :+ (k+homes.head))).map{case (x, y) => scala.math.abs(y - x)}.max).toString)
}
