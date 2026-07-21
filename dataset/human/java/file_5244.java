import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*

fun main(args : Array<String>) {
    val scan = FastScanner(System.`in`)

    var s = scan.next()
    val q = scan.nextInt()

    var rvFlag = false
    val str = ArrayDeque<Char>(s.toList())

    repeat(q) {
        val q1 = scan.nextInt()

        if (q1 == 1) {
            rvFlag = !rvFlag
        } else {
            val q2 = scan.nextInt()
            val c = scan.next()[0]

            if (rvFlag) {
                if (q2 == 1) {
                    str.addLast(c)
                } else {
                    str.addFirst(c)
                }
            } else {
                if (q2 == 1) {
                    str.addFirst(c)
                } else {
                    str.addLast(c)
                }
            }
        }
    }

    if (rvFlag) {
        println(str.reversed().joinToString(separator = ""))
    } else {
        println(str.joinToString(separator = ""))
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
