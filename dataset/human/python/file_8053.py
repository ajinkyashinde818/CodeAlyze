object Main {
  def main(args: Array[String]) = {
    val Array(k, s) = readLine.split(" ").map(_.toInt)

    val list = (0 to k).toList

    val res = list.foldRight(0) { (x, t) => t + list.foldRight(0) { (y, t2) => t2 + (if (0 <= (s - x - y) && (s - x - y) <= k) 1 else 0) } }
    println(res)
  }
}
