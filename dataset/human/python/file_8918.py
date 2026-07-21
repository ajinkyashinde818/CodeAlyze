object Main {
  def main(args: Array[String]): Unit = {
    val s = io.StdIn.readLine()

    val suffixes = Seq("dream", "dreamer", "erase", "eraser")
    def loop(t: String): Boolean = {
      if(t.isEmpty) true
      else {
        suffixes.find(t.endsWith(_)) match {
          case None => false
          case Some(suf) =>
            loop(t.substring(0, t.length - suf.length))
        }
      }
    }
    println(if(loop(s)) "YES" else "NO")
  }
}
