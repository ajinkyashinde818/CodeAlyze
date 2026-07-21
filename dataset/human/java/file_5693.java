import java.io.*
import java.util.*
import java.lang.*
import java.lang.Math.*


fun solve() {
    val (N, K, S) = rd.readIntArray()

    val NONE = if (S == 1_000_000_000) 999_999_999
                   else 1_000_000_000

    val A = IntArray(N){NONE}
    for (i in 0 until K) {
        A[i] = S
    }

    println(A.joinToString(" "))
}


//val rd = debug.Reader("etc", "keyence2020", "c", "sample-1")
val rd = Reader()


fun main(args: Array<String>) {
    try {
        var exception: Throwable? = null
        val sth = Thread(null, SolveThread(), "solveThread", 128 * 1024 * 1024)
        sth.setUncaughtExceptionHandler { _, e -> exception = e }
        sth.start(); sth.join()
        if (exception != null) throw exception!! }
    catch (e: Exception) { throw e }
    finally { rd.close() }
}
const val MOD = 1_000_000_007L; const val INF = Int.MAX_VALUE/2; const val LINF = Long.MAX_VALUE/2
const val EPS = 1e-9; fun DBLEQ(a: Double, b: Double): Boolean {return abs(a - b) < EPS}
data class IntPair(val first: Int, val second: Int)
data class To(val idx: Int, val cost: Long)
typealias ALI = ArrayList<Int>
fun <T>edge(V: Int): Array<ArrayList<T>> { return Array(V){ArrayList<T>()} }
val errPrintln: (Any) -> Unit = { msg -> System.err.println(msg) }
fun rAssert(exp: Boolean, lazyMsg: () -> String = {""}) {
    if (!exp) { val msg = lazyMsg(); errPrintln("EAssert Error: $msg"); throw Error(msg) }
}
fun tAssert(exp: Boolean, lazyMsg: () -> String = {""}) {
    if (!exp) { val msg = lazyMsg(); errPrintln("TAssert Error: $msg"); Thread.sleep(3000) }
}
class SolveThread : Runnable {
    override fun run() { solve() }
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
    val readListIntCol: (Int) -> List<Int> = { N -> (0 until N).map { readInt() } }
    val readListLongCol: (Int) -> List<Long> = { N -> (0 until N).map { readLong() } }
    val close: () -> Unit = { br.close() }
    protected fun finalize() { close() }
}
