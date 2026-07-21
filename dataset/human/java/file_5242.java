import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.*

fun main(args: Array<String>) {
    val sc = FastScanner(System.`in`)
    val s = sc.nextLine()
    val q = sc.nextInt()
    var refl = 1
    var front = StringBuilder()
    var end = StringBuilder()
    for (i in 0 until q) {
        val t = sc.nextInt()
        if (t == 1) {
            refl *= -1
        } else {
            val f = sc.nextInt()
            val c = sc.next()
            if ((f == 1 && refl == 1) || (f == 2 && refl == -1)) {
                front.append(c)
            } else {
                end.append(c)
            }
        }
    }
    val ans = front.toString().reversed() + s + end.toString()
    if (refl == 1) {
        println(ans)
    } else {
        println(ans.reversed())
    }
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
