import scala.util.control.Breaks._

object Main {
  def main(args:Array[String]) = {
    val sc = new java.util.Scanner(System.in)
    val s = sc.next

    var index = s.length
    val words = List("dreamer", "dream", "eraser", "erase")
    val lens = words.map(_.length)
    breakable { while (index >= 0) {
      var deleted = false
      breakable { for ((word, len) <- words zip lens) {
        if (s.slice(0, index).endsWith(word)) {
          index -= len
          deleted = true
          break
        }
      } }
      if (! deleted) break
    } }
    println(if (index == 0) "YES" else "NO")
  }
}
