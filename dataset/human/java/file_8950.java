import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    val a = sc.nextInt()
    val b = sc.nextInt()
    val k = sc.nextInt()
    var count = 0
    for (i in 1000 downTo 1) {
        if (a % i == 0 && b % i == 0) {
            count++
            if (count == k) {
                println(i)
                return
            }
        }
    }
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
