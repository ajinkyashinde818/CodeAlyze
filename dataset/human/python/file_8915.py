object Main extends App {
  val s = readLine  
  val list = Seq("dream", "dreamer", "erase", "eraser")
  
  def check(str: String): Boolean = {
    val index = list.indexWhere(str.endsWith)

    if (str.isEmpty) true
    else if (index == -1) false
    else check(str.dropRight(list(index).length))
  }
  
  val result = check(s)
  println(if (result) "YES" else "NO")
}
