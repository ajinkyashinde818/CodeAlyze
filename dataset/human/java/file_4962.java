import java.io.*
import java.util.*

fun solve(N: Long) {
    if (N % 2L == 0L) {
        // N = 2m
        // N!! = 2^m * m!
        val m = N / 2
        val ans = m.powerOfFactorial(5L)
        println(ans)
    } else {
        println(0)
    }
    return
}

fun Long.powerOfFactorial(base: Long): Long {
    // this! がbaseで何回割り切れるか
    // [this / base] + [this/base*base] + ...
    var count = 0L
    var ret = base
    while (ret <= this) {
        count += (this / ret)
        ret *= base
    }
    return count
}

fun main(args: Array<String>) {
    fun StringArray(size: Int, init: (Int) -> String = { "\u0000" }): Array<String> {
        return Array<String>(size, init)
    }
    class Scanner(stream: InputStream) {
        private val reader = BufferedInputStream(stream).bufferedReader()
        private var st: StringTokenizer? = null
        fun next(): String {
            while (!(st?.hasMoreTokens() ?: false)) st = StringTokenizer(reader.readLine())
            return st!!.nextToken()
        }
    }
    val sc = Scanner(System.`in`)
    val N = sc.next().toLong()
    solve(N)
}
