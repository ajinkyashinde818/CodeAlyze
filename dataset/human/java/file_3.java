import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*

fun main(args: Array<String>) {
    val sc = FastScanner(System.`in`)
    val R = sc.nextInt()
    val G = sc.nextInt()
    val B = sc.nextInt()
    val n = sc.nextInt()

    val use = listOf(R, G, B)
    val dp = Array(7000) { Array(3) { 0 } }
    dp[0][0] = 1

    for (x in 0..n) {
        for (u in 0..2) {
            for (k in u..2) {
                dp[x + use[k]][k] += dp[x][u]
            }
        }
    }

    println(dp[n][0] + dp[n][1] + dp[n][2] )
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
