object Main {
  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val S = sc.next

    def rec(s: String): String = {
      if (s.isEmpty) {
        println("YES")
        sys.exit()
      }
      if (s.startsWith("dream")) {
        if (s.startsWith("dreameraser")) {
          rec(s.replaceFirst("dreameraser", ""))
        } else if (s.startsWith("dreamerase")) {
          rec(s.replaceFirst("dreamerase", ""))
        } else if (s.startsWith("dreamer")) {
          rec(s.replaceFirst("dreamer", ""))
        } else {
          rec(s.replaceFirst("dream", ""))
        }
      } else if (s.startsWith("erase")) {
        if (s.startsWith("eraser")) {
          rec(s.replaceFirst("eraser", ""))
        } else {
          rec(s.replaceFirst("erase", ""))
        }
      } else {
        println("NO")
        sys.exit()
      }
    }

    rec(S)
  }
}
