import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.StringBuilder
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    val n = sc.nextLong()
    var m = n
    val pf = mutableMapOf<Long, Int>()
    var d = 2L
    while (d * d <= m) {
        var count = 0
        while (m % d == 0L) {
            m /= d
            count++
        }
        if (count > 0) {
            pf[d] = count
        }
        d++
    }
    if (m > 1) {
        pf[m] = 1
    }
    var ans = 0L
    for (e in pf.values) {
        var rem = e
        for (i in 1..e) {
            if (rem >= i) {
                rem -= i
                ans++
            } else {
                break
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
