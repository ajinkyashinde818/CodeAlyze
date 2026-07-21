import java.io.{PrintWriter, _}
import java.util
import java.util._


object Main {
  def main(args: Array[String]): Unit = {
    val inputStream = System.in
    val outputStream = System.out
    val in = new InputReader(inputStream)
    val out = new PrintWriter(outputStream)
    val solver = new Task
    solver.solve(1, in, out)
    out.close()
  }

  class Task {
    def solve(testNumber: Int, in: InputReader, out: PrintWriter): Unit = {
      val a = in.next
      if (a.contains("9")) out.println("Yes") else out.println("No")
    }
  }

  class InputReader(val stream: InputStream) extends AutoCloseable {
    //reader = new BufferedReader(new FileReader(stream), 32768);
    private val reader = new BufferedReader(new InputStreamReader(stream), 32768)
    private var tokenizer = new StringTokenizer("")


    def next: String = {
      while ( {
        tokenizer == null || !tokenizer.hasMoreTokens
      }) try
        tokenizer = new StringTokenizer(reader.readLine)
      catch {
        case e: IOException =>
          throw new RuntimeException(e)
      }
      tokenizer.nextToken
    }

    def nextLine: String = {
      try
        return reader.readLine
      catch {
        case e: IOException =>
          e.printStackTrace()
      }
      ""
    }

    def nextInt: Int = next.toInt

    def nextLong: Long = next.toLong

    override def close(): Unit = {
    }
  }

}
