import java.lang.Math.min
import java.lang.Math.sqrt

const val MOD = 1000000007L
const val INF = 1000000007L


fun main(args: Array<String>) {
    val (a, b, k) = readIntList()

    var ret = 0
    min(a, b).rep(0) { i ->
        val it = min(a, b) - i
        if (a % it == 0 && b % it == 0) {
            ret++
            if (ret == k) {
                println(it)
                return
            }
        }
    }
}

fun readList() = readLine()!!.split(' ')
fun readInt() = readLine()!!.split(' ').map(String::toInt).first()
fun readIntList() = readList().map(String::toInt)
fun readLongList() = readList().map(String::toLong)
fun readDoubleList() = readList().map(String::toDouble)

fun readPair(): Pair<String, String> {
    val splite = readLine()!!.split(' ')
    return Pair(splite[0], splite[1])
}

fun <T> List<T>.copy() = this.map { it }

fun Long.toBinaryString(): String {
    var t = this
    var res = ""
    while (t > 0) {
        res += (t % 2).toString()
        t /= 2
    }
    return res
}

inline fun <reified T> dualArray(h: Int, w: Int, init: (Int, Int) -> T) {
    Array(h) { i ->
        return@Array Array(w) { j ->
            return@Array init(i, j)
        }
    }
}

// 速度のためforEachは避ける
inline fun Int.rep(start: Int = 0, shiftLast: Boolean = false, body: (Int) -> Unit) {
    for (i in start until if (shiftLast) this + start else this) {
        body(i)
    }
}

inline fun Long.rep(start: Long = 0, shiftLast: Boolean = false, body: (Long) -> Unit) {
    for (i in start until if (shiftLast) this + start else this) {
        body(i)
    }
}

// 約数のList
fun divisor(value: Long): List<Long> {
    val max = sqrt(value.toDouble()).toLong()
    val former = mutableListOf<Long>()
    val latter = mutableListOf<Long>()
    (1..max).filter { value % it == 0L }
        .forEach {
            former.add(it)
            latter.add(value / it)
        }
    former.addAll(latter.reversed())
    return former
}

// 範囲内の素数を取得
// fromだけ指定すると戻り値の個数で素数判定ができる
fun prime(from: Long, to: Long = from): List<Long> {
    return (from..to).filter { i ->
        val max = Math.sqrt(i.toDouble()).toLong()
        (2..max).all { j -> i % j != 0L }
    }
}

// 素因数分解
fun decom(value: Long): List<Long> {
    if (value == 1L) return listOf(1)
    val max = Math.sqrt(value.toDouble()).toLong()
    return prime(2, max).filter { value % it == 0L }
}

// 最大公約数
fun gcd(a: Long, b: Long): Long {
    return if (a % b == 0L) b else gcd(b, a % b)
}

// 文字列を入れ替え
fun swap(base: String, a: String, b: String): String {
    return base.map {
        when (it) {
            a.toCharArray()[0] -> b
            b.toCharArray()[0] -> a
            else -> it.toString()
        }
    }.joinToString()
}

// 二分探索
fun List<Long>.binarySearch(target: Long, _start: Int = 0, _end: Int = this.size): Int {
    var start = (_start - 1).toLong()
    var end = _end.toLong()
    while (end - start > 1) {
        val mid = (start + end) / 2
        if (this[mid.toInt()] < target) {
            start = mid
        } else {
            end = mid
        }
    }
    return end.toInt()
}

// bit全探索
inline fun Int.bitAllSearch(body: (Array<Int>) -> Unit) {
    for (bit in 0 until (1 shl this)) {
        val s = mutableListOf<Int>()
        for (i in 0 until this) {
            if ((bit and (1 shl i)) shr i == 1) { // i が bit に入るかどうか
                s.add(i)
            }
        }
        body(s.toTypedArray())
    }
}


internal class UnionFindTree(size: Int) {

    private val parent = Array(size) {
        return@Array it
    }
    private val rank = Array(size) {
        return@Array 0
    }

    fun union(x: Int, y: Int): Int {
        val xRoot = find(x)
        val yRoot = find(y)

        if (xRoot == yRoot) return xRoot

        when {
            rank[xRoot] > rank[yRoot] -> parent[yRoot] = xRoot
            rank[xRoot] < rank[yRoot] -> parent[xRoot] = yRoot
            xRoot != yRoot -> {
                parent[yRoot] = xRoot
                rank[xRoot]++
            }
        }
        return parent[xRoot]
    }

    fun find(i: Int): Int {
        if (i != parent[i]) {
            parent[i] = find(parent[i])
        }
        return parent[i]
    }

    fun same(x: Int, y: Int): Boolean {
        return find(x) == find(y)
    }
}
