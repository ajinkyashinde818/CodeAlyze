import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.lang.Math.*


val MOD = 1_000_000_007L
val INF = Int.MAX_VALUE/2
val LINF = Long.MAX_VALUE/2
data class IntPair(val first: Int, val second: Int)
data class To(val idx: Int, val cost: Long)
val errPrintln: (Any) -> Unit = { msg -> System.err.println(msg) }

//val rd = debug.Reader("abc", "171", "d", "sample-1")
val rd = Reader()


fun solveD(N: Int, K: Long, A:Array<Int>): Int {
    var step = Array<Long>(N){-1}
    fun dfs(x: Int, sp:Long): Pair<Int, Long> {
        if (sp>=K) {
            return Pair(x, -1L);
        }

        if (step[x] >= 0L) {
            return Pair(x,sp)
        }

        step[x] = sp
        return dfs(A[x], sp + 1L)
    }

    var pos = dfs(0, 0L)
    if (pos.second < 0L) {
        return pos.first + 1;
    }

    val move = (K - step[pos.first]) % (pos.second - step[pos.first])

    fun dfs2(n: Long, x: Int): Int {
        if (n >= move) {
            return x
        }
        return dfs2(n + 1L, A[x])
    }

    return dfs2(0L, pos.first) + 1
}


fun main() {
    val (n,K) = rd.readListLong()
    val N = n.toInt()
    val a = rd.readListInt()
    var A = Array<Int>(N){0}
    for(i in 0 until N) {
        A[i] = a[i] - 1
    }

    val ans = solveD(N, K, A)

    println(ans)
}



class Main : Runnable {
    override fun run() { main() }
}
fun main(args: Array<String>) {
    Thread(null, Main(), "mainThread", 128 * 1024 * 1024).start()
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
