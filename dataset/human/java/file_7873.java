import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.io.PrintWriter
import java.lang.StringBuilder
import java.util.*

fun PrintWriter.solve(sc: FastScanner) {
    val n = sc.nextInt()
    val k = sc.nextLong()
    val a = Array(n) { sc.nextInt() - 1 }
    val set = mutableSetOf(0)
    var v = 0
    do {
        v = a[v]
    } while (set.add(v))
    val lst1 = mutableListOf<Int>()
    var w = 0
    while (w != v) {
        lst1.add(w)
        w = a[w]
    }
    val lst2 = mutableListOf(v)
    w = a[w]
    while (w != v) {
        lst2.add(w)
        w = a[w]
    }
    if (k < lst1.count()) {
        println(lst1[k.toInt()] + 1)
    } else {
        val i = k - lst1.count()
        println(lst2[(i % lst2.count()).toInt()] + 1)
    }
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
