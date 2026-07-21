import java.util.*
import java.math.*
import java.lang.Math.*

private val readString: ()->String = {readLine()!!}
private val readInt: ()->Int = {readLine()!!.toInt()}
private val readLong: ()->Long = {readLine()!!.toLong()}
private val readIntArray: ()->IntArray = {readLine()!!.split(' ').map{it.toInt()}.toIntArray()}
private val readLongArray: ()->LongArray = {readLine()!!.split(' ').map{it.toLong()}.toLongArray()}
private val errPrintln: (String)->Unit = {msg -> System.err.println(msg)}
private val MOD = 1e9.toLong()+7
private val INF = Int.MAX_VALUE/2
private val LINF = Long.MAX_VALUE/2


data class PairInt(val first: Int, val second: Int)
fun greedyBitFS(item: Array<PairInt>, bonus: IntArray, LowLimit: Int): Int {
    val N = item.size
    var res = Int.MAX_VALUE;
    for (p in 0 until (0b01 shl N)) {
        var ptn = p
        var scr = 0
        var cnt = 0
        var lv = -1
        for(i in 0 until N) {
            val vi = item[i].first
            val ci = item[i].second
            if ((ptn and 0b01) == 1) {
                scr += vi * ci + bonus[i]
                cnt += ci;
                if (scr >= LowLimit) {
                    res = min(res, cnt)
                }
            } else {
                lv = max(lv, i)
            }
            ptn = ptn shr 1
        }
        if (scr < LowLimit) {
            if (lv >= 0) {
                val v = item[lv].first
                val c = item[lv].second
                val dc = min((LowLimit - scr + v - 1) / v, c - 1)
                if (scr + v*dc >= LowLimit) {
                    res = min(res, cnt + dc)
                }
            }
        }
    }
    return res
}


fun solveC(G: Int, P: IntArray, C: IntArray): Int {
    val D = P.size
    val items = Array<PairInt>(D){PairInt(0,0)}
    for (i in 0 until D) {
        items[i] = PairInt(100*(i+1), P[i])
    }

    return greedyBitFS(items, C, G)
}


fun main(args: Array<String>) {
    val (D,G) = readIntArray()
    val P = IntArray(D){0}
    val C = IntArray(D){0}
    for(i in 0 until D) {
        val (p, c) = readIntArray()
        P[i] = p; C[i] = c
    }

    val ans = solveC(G, P, C)

    println(ans)
}
