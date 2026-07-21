import scala.io.{ StdIn => in}

object Main extends App {
  val s = in.readLine
    .replaceAll("eraser","")
    .replaceAll("erase","")
    .replaceAll("dreamer","")
    .replaceAll("dream","")

  val ans = if(s.isEmpty) "YES" else "NO"
  println(ans)
}
