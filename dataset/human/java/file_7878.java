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

////////////////////////////////////////////////////////////////////////

object Problem {
    fun solve(sc: Scanner, pw: java.io.PrintWriter) {
        val N = sc.next().toInt()
        val K = sc.next().toLong()
        val A = IntArray(N) { sc.next().toInt() - 1 }
        val to = Array(N) { IntArray(60) }
        for (i in 0 until N) to[i][0] = A[i]
        repeat(59) { r ->
            repeat(N) { i ->
                to[i][r + 1] = to[to[i][r]][r]
            }
        }
        //to.forEach { println(it.joinToString(" "))}

        var k = K
        var ans = 0
        for (r in 59 downTo 0) {
            val l = 1L shl r
            if (k >= l) {
                ans = to[ans][r]
                k -= l
            }
        }
        pw.println(ans + 1)
    }
}
