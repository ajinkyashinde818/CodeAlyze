import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    val n = sc.nextInt()
    val d = Array(n) { Array(2) { sc.nextInt() } }
    for (i in 0 until n - 2) {
        if (d[i][0] == d[i][1] && d[i + 1][0] == d[i + 1][1] && d[i + 2][0] == d[i + 2][1]) {
            println("Yes")
            return
        }
    }
    println("No")
}

fun main() {
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
