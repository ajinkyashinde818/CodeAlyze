import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.StringBuilder
import java.math.BigInteger
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    val r = sc.nextInt()
    val g = sc.nextInt()
    val b = sc.nextInt()
    val n = sc.nextInt()
    var ans = 0L
    for (i in 0..n) {
        for (j in 0..n) {
            val x = n - i * r - j * g
            if (x < 0) continue
            if (x % b == 0) {
                ans++
            }
        }
    }
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
