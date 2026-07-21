import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.StringBuilder
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    val n = sc.nextInt()
    val s = sc.nextLine()
    val count = mutableMapOf<Char, Int>()
    for (c in s) {
        count[c] = (count[c] ?: 0) + 1
    }
    var ans = 1L
    for (v in count.values) {
        ans *= v + 1
        ans %= 1000000007
    }
    ans--
    println(ans)
}

fun main(args: Array<String>) {
    val writer = PrintWriter(System.out, false)
    writer.solve(FastScanner(System.`in`))
    writer.flush()
}

class FastScanner(s: InputStream) {
    private var st = StringTokenizer("")
    private val br = BufferedReader(InputStreamReader(s))

    fun next(): String {
        while (!st.hasMoreTokens()) st = StringTokenizer(br.readLine())

        return st.nextToken()
    }

    fun nextInt() = next().toInt()
    fun nextLong() = next().toLong()
    fun nextLine() = br.readLine()
    fun nextDouble() = next().toDouble()
    fun ready() = br.ready()
}
