import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.StringBuilder
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    val n = sc.nextInt()
    val m = sc.nextInt()
    val a = Array(m) { sc.nextInt() }
    val isbroken = BitSet(n + 1)
    for (i in 0 until m) {
        isbroken[a[i]] = true
    }
    val dp = Array(n + 1) { 0L }
    dp[0] = 1
    for (i in 0 until n) {
        if (!isbroken[i + 1]) {
            dp[i + 1] = dp[i] + (if (i > 0) dp[i - 1] else 0)
            dp[i + 1] %= 1000000007L
        }
    }
    println(dp[n])
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
