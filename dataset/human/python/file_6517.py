import scala.collection.mutable

object Main {
  val T_REVERSE = 1
  val T_COMMAND = 2
  val F_PREPEND = 1
  val F_APPEND = 2

  def main(args: Array[String]): Unit = {
    val sc = new java.util.Scanner(System.in)
    val original = sc.next()
    val commandLength = sc.nextInt()

    var isReversed = false
    var prependList: mutable.ListBuffer[Char] = mutable.ListBuffer()
    var appendList: mutable.ListBuffer[Char] = mutable.ListBuffer()

    1.to(commandLength).foreach { _ =>
      val commandT = sc.nextInt()

      if (commandT == T_REVERSE) {
        isReversed = !isReversed
      } else if (commandT == T_COMMAND) {
        val commandF = sc.nextInt()
        val char = sc.next().charAt(0)
        if ((commandF == F_PREPEND && !isReversed) || (commandF == F_APPEND && isReversed)) {
          prependList += char
        } else {
          appendList += char
        }
      }
    }

    val ans =
      if (isReversed) {
        val pre = appendList.mkString.reverse
        val orig = original.reverse
        val post = prependList.mkString
        pre + orig + post
      } else {
        val pre = prependList.mkString.reverse
        val post = appendList.mkString
        pre + original + post
      }

    println(ans)
  }
}
