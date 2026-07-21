import java.io.*
import java.util.*
import java.lang.*
import java.lang.Math.*


fun solve() {
    val S = rd.readString()
    val N = S.length

    var cnt = 0
    var i = 0; var j = N-1
    while (i < j) {
        if (S[i] == S[j]) {
            i++
            j--
        } else {
            if (S[i] == 'x') {
                i++
                cnt++
            } else if (S[j] == 'x') {
                j--
                cnt++
            } else {
                println(-1)
                return
            }
        }
    }

    val ans = cnt
    println(ans)
}


//val rd = debug.Reader("etc", "code-festival-2017-qualc", "c", "sample-1")
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
    val readListIntCols: (Int) -> List<List<Int>> = { N -> (0 until N).map { br.readLine().split(' ').map { it.toInt() } } }
    val readListLongCol: (Int) -> List<Long> = { N -> (0 until N).map { readLong() } }
    val close: () -> Unit = { br.close() }
    protected fun finalize() { close() }
}
