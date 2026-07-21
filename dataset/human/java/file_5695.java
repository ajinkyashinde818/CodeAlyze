import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) {
    val sc = FastScanner(System.`in`)


    val n = sc.nextInt()
    val k = sc.nextInt()
    val s = sc.nextInt()

/*
    val random = Random()

    repeat(100000) {
        val n = 1 + random.nextInt(100)
        val k = random.nextInt(n + 1)
        val s = random.nextInt(100) + 1
*/

/*
        val n = 7
        val k = 5
        val s = 20
*/
        val res = buildString {
            if (n == k) {
                repeat(n) { append("$s ") }
            } else {
                if (s == 1) {
                    repeat(k) { append("1 ") }
                    repeat(n - k) { append("2 ") }
                } else if (s == 1e9.toInt()) {
                    repeat(k) { append("${1e9.toInt()} ") }
                    repeat(n - k) { append("2 ") }
                } else {
                    for (i in 0..k) {
                        if (i % 2 == 0) append("1 ")
                        else append("${s - 1} ")
                    }
                    repeat(n - k - 1) {
                        append("${s + 1} ")
                    }
                }
            }
        }
        println(res.trim())

/*
        if (!check(n, k, s, res)) {
            println("$n $k $s")
            println("Broken")
            return
        }
    }
*/
}

fun check(n: Int, k: Int, s: Int, res: String): Boolean {
    val a = res.trim().split(" ").map { it.toInt() }
    if (a.size != n) return false

    var c = 0
    for (l in 0 until n) {
        var sum = 0L
        for (r in l until n) {
            sum += a[r]
            if (sum == s.toLong()) c++
        }
    }
    //println(c)
    return c == k
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
