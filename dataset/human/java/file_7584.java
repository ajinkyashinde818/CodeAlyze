import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.StringBuilder
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    var s = sc.nextLine()
    var ok = true
    do {
        ok = false
        if (s.endsWith("eraser")) {
            s = s.removeSuffix("eraser")
            ok = true
        } else if (s.endsWith("erase")) {
            s = s.removeSuffix("erase")
            ok = true
        } else if (s.endsWith("dreamer")) {
            s = s.removeSuffix("dreamer")
            ok = true
        } else if (s.endsWith("dream")) {
            s = s.removeSuffix("dream")
            ok = true
        }
    } while (ok)
    println(if (s.length == 0) "YES" else "NO")
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
