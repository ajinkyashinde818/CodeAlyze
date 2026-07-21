import java.io.*
import java.util.*
import java.lang.Math.*


fun primeFactorize(N: Long): Map<Long, Int> {
    if (N <= 1L) return mapOf()
    val fact = mutableMapOf<Long, Int>()
    var n = N
    var i = 2L
    while (i * i <= n) {
        while (n%i == 0L) {
            fact[i] = (fact[i] ?: 0) + 1
            n /= i
        }
        i++
    }
    if (n != 1L) {
        fact[n] = (fact[n] ?: 0) + 1
    }
    return fact
}


fun main() {
    val N = rd.readLong()

    val fs = primeFactorize(N).toMutableMap()

    var ans = 0
    var num = 1
    while (true) {
        var updated = false
        for ((k, v) in fs) {
            if (v >= num) {
                fs[k] = fs[k]!! - num
                ans++
                updated = true
            }
        }
        if (!updated) break
        num++
    }


    println(ans)
}


//val rd = debug.Reader("abc", "169", "d", "sample-1")
val rd = Reader()
fun main(args: Array<String>) {
    Thread(null, MainThread(), "mainThread", 128 * 1024 * 1024).start()
}


const val MOD = 1_000_000_007L; const val INF = Int.MAX_VALUE/2; const val LINF = Long.MAX_VALUE/2
val EPS = 1e-9; fun DBLEQ(a: Double, b: Double): Boolean {return abs(a - b) < EPS}
data class IntPair(val first: Int, val second: Int)
data class To(val idx: Int, val cost: Long)
fun <T>edge(V: Int): Array<ArrayList<T>> { return Array(V){ArrayList<T>()} }
val errPrintln: (Any) -> Unit = { msg -> System.err.println(msg) }
class MainThread : Runnable {
    override fun run() { main() }
}
class Reader {
    private val br = BufferedReader(InputStreamReader(System.`in`))
    val readString: () -> String = { br.readLine() }
    val readInt: () -> Int = { br.readLine().toInt() }
    val readLong: () -> Long = { br.readLine().toLong() }
    val readIntArray: () -> IntArray = { br.readLine().split(' ').map { it.toInt() }.toIntArray() }
    val readLongArray: () -> LongArray = { br.readLine().split(' ').map { it.toLong() }.toLongArray() }
    val readListInt: () -> List<Int> = { br.readLine().split(' ').map { it.toInt() } }
    val readListLong: () -> List<Long> = { br.readLine().split(' ').map { it.toLong() } }
}
