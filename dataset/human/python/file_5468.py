object Main {
  def main(args: Array[String]) {
    val sc = new java.util.Scanner(System.in)
    val X = sc.next().charAt(0)
    val Y = sc.next().charAt(0)
    val r = if (X > Y) '>' else if (X < Y) '<' else '='
    println(r)
  }
}
