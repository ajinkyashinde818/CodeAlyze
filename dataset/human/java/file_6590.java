import java.util.*

class Scanner(`in`: java.io.InputStream) {
    private val reader = java.io.BufferedReader(java.io.InputStreamReader(`in`))
    private var tokenizer: StringTokenizer? = null

    fun next(): String {
        if (tokenizer?.hasMoreTokens() != true) {
            tokenizer = StringTokenizer(reader.readLine())
        }
        return tokenizer!!.nextToken()
    }

    fun nextLine(): String {
        return if (tokenizer?.hasMoreTokens() != true) {
            reader.readLine()
        } else tokenizer!!.nextToken("\n")
    }
}

fun main(args: Array<String>) {
    val pw = java.io.PrintWriter(System.out)
    Problem.solve(Scanner(System.`in`), pw)
    pw.flush()
}

////////////////////////////////////////////////////////////////////////

object Problem {
    fun solve(sc: Scanner, pw: java.io.PrintWriter) {
        val K = sc.next().toInt()
        val S = sc.next().toInt()
        var ans = 0L
        for (x in 0..K) {
            for (y in 0..K) {
                val z = S - (x + y)
                if (z in 0..K) ans++
            }
        }
        pw.println(ans)
    }
}
