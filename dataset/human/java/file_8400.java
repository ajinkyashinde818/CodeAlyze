import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.IllegalArgumentException
import java.lang.StringBuilder
import java.lang.reflect.Modifier
import java.util.*

fun gcd(a:Long, b:Long):Long {
    if (b == 0L) return a
    return gcd(b, a % b)
}

fun lcm(a:Long, b:Long):Long {
    return a / gcd(a, b) * b
}

fun PrintWriter.solve(sc: FastScanner) {
    val a = sc.nextLong()
    val b = sc.nextLong()
    println(lcm(a, b))
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
