import java.io.*
import java.lang.*
import java.math.BigDecimal
import java.util.*

// Constant
val sc = FastScanner()
val pw = PrintWriter(System.out)
const val MOD = 1000000007L
const val INF = 9223372036854775807L

// Main
fun main(args: Array<String>) {
    solve()
    pw.flush()
}

fun solve() {
    val s = next()
    val len = s.length
    val ans = s.substring(0, len - 8)

    println(ans)
}



// Rule
operator fun String.get(index: Long): Char {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    return this[index.toInt()]
}
operator fun CharArray.get(index: Long): Char {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    return this[index.toInt()]
}
operator fun CharArray.set(index: Long, value: Char) {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    this[index.toInt()] = value
}
operator fun LongArray.get(index: Long): Long {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    return this[index.toInt()]
}
operator fun LongArray.set(index: Long, value: Long) {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    this[index.toInt()] = value
}
operator fun DoubleArray.get(index: Long): Double {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    return this[index.toInt()]
}
operator fun DoubleArray.set(index: Long, value: Double) {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    this[index.toInt()] = value
}
operator fun <T> Array<T>.get(index: Long): T {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    return this[index.toInt()]
}
operator fun <T> Array<T>.set(index: Long, value: T) {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    this[index.toInt()] = value
}
operator fun <T> MutableList<T>.get(index: Long): T {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    return this[index.toInt()]
}
operator fun <T> MutableList<T>.set(index: Long, value: T) {
    if (index !in 0L..Int.MAX_VALUE) throw IllegalArgumentException()
    this[index.toInt()] = value
}

val LongArray.siz: Long
    get() = size.toLong()
val <T> Array<T>.siz: Long
    get() = size.toLong()
val <T> MutableList<T>.siz: Long
    get() = size.toLong()
val <T> MutableSet<T>.siz: Long
    get() = size.toLong()
val String.len: Long
    get() = length.toLong()

// Output
fun println(v: String) {
    pw.println(v)
}
fun print(v: String) {
    pw.print(v)
}

// Input
fun next() = sc.next()
fun nextLong() = sc.nextLong()
fun nextDouble() = next().toDouble()
fun nextAry(n: Long): Array<String> {
    val ary = ary(n)
    for (i in 0 until n) ary[i] = next()
    return ary
}
fun nextLongAry(n: Long): LongArray {
    val ary = longAry(n)
    for (i in 0 until n) ary[i] = nextLong()
    return ary
}
fun nextDoubleAry(n: Long): DoubleArray {
    val ary = doubleAry(n)
    for (i in 0 until n) ary[i] = nextDouble()
    return ary
}

// Statement
fun ary(n: Long, init: String = "") = Array(n.toInt()) { init }
fun longAry(n: Long, init: Long = 0L) = LongArray(n.toInt()) { init }
fun doubleAry(n: Long, init: Double = 0.0) = DoubleArray(n.toInt()) { init }
fun boolAry(n: Long, init: Boolean = false) = Array(n.toInt()) { init }
fun ary2(n: Long, m: Long, init: String = "") = Array(n.toInt()) { ary(m, init) }
fun longAry2(n: Long, m: Long, init: Long = 0) = Array(n.toInt()) { longAry(m, init) }
fun doubleAry2(n: Long, m: Long, init: Double = 0.0) = Array(n.toInt()) { doubleAry(m, init) }
fun boolAry2(n: Long, m: Long, init: Boolean = false) = Array(n.toInt()) { boolAry(m, init) }
fun ary3(n: Long, m: Long, k: Long, init: String = "") = Array(n.toInt()) { ary2(m, k, init) }
fun longAry3(n: Long, m: Long, k: Long, init: Long = 0L) = Array(n.toInt()) { longAry2(m, k, init) }
fun doubleAry3(n: Long, m: Long, k: Long, init: Double = 0.0) = Array(n.toInt()) { doubleAry2(m, k, init) }
fun boolAry3(n: Long, m: Long, k: Long, init: Boolean = false) = Array(n.toInt()) { boolAry2(m, k, init) }
fun list() = mutableListOf<String>()
fun longList() = mutableListOf<Long>()
fun doubleList() = mutableListOf<Double>()
fun strSet() = mutableSetOf<String>()
fun longSet() = mutableSetOf<Long>()
fun doubleSet() = mutableSetOf<Double>()
fun <E, V> map() = mutableMapOf<E, V>()

// Monoid
val addFunc = {a: Long, b: Long -> a + b}
val mulFunc = {a: Long, b: Long -> a * b}
val maxFunc = {a: Long, b: Long -> max(a, b)}
val minFunc = {a: Long, b: Long -> min(a, b)}
val gcdFunc = {a: Long, b: Long -> gcd(a, b)}
val lcmFunc = {a: Long, b: Long -> lcm(a, b)}
val xorFunc = {a: Long, b: Long -> a xor b}
fun calc(a: Long, b: Long, op: (Long, Long) -> Long) = op(a, b)

// Extension
fun LongArray.lowerBound(n: Long): Long {
    var ok = this.size.toLong()
    var ng = -1L
    while (abs(ok - ng) > 1) {
        val mid = (ok + ng) / 2
        if (this[mid] >= n) ok = mid
        else ng = mid
    }
    return ok
}
fun DoubleArray.lowerBound(n: Double): Long {
    var ok = this.size.toLong()
    var ng = -1L
    while (abs(ok - ng) > 1) {
        val mid = (ok + ng) / 2
        if (this[mid] >= n) ok = mid
        else ng = mid
    }
    return ok
}
fun MutableList<Long>.longLowerBound(n: Long): Long {
    var ok = this.size.toLong()
    var ng = -1L
    while (abs(ok - ng) > 1) {
        val mid = (ok + ng) / 2
        if (this[mid] >= n) ok = mid
        else ng = mid
    }
    return ok
}
fun MutableList<Double>.doubleLowerBound(n: Double): Long {
    var ok = this.size.toLong()
    var ng = -1L
    while (abs(ok - ng) > 1) {
        val mid = (ok + ng) / 2
        if (this[mid] >= n) ok = mid
        else ng = mid
    }
    return ok
}
fun LongArray.cumsum(op: (Long, Long) -> Long): LongArray {
    val s = longAry(this.size + 1L)
    s[1] = this[0]
    for (i in 1 until this.size) s[i + 1] = calc(s[i], this[i], op)
    return s
}
fun MutableMap<String, Int>.counting(n: Long) {
    repeat(n.toInt()) {
        val a = next()
        if (this.containsKey(a)) this[a] = this[a]!! + 1
        else this[a] = 1
    }
}
fun MutableMap<Long, Int>.longCounting(n: Long) {
    repeat(n.toInt()) {
        val a = nextLong()
        if (this.containsKey(a)) this[a] = this[a]!! + 1
        else this[a] = 1
    }
}

// Mathematics
fun abs(n: Long): Long = Math.abs(n)
fun abs(n: Double): Double = Math.abs(n)
fun max(vararg values: Long) = if (values.isEmpty()) -INF else values.max()!!
fun min(vararg values: Long) = if (values.isEmpty()) INF else values.min()!!
tailrec fun gcd(a: Long, b: Long): Long = if (b == 0L) a else if (a % b == 0L) b else gcd(b, (a % b))
fun lcm(a: Long, b: Long): Long = a / gcd(a, b) * b
fun modpow(a: Long, n: Long, p: Long = MOD): Long {
    var res = 1L
    var ar = a
    var nr = n
    while (nr > 0) {
        if ((nr and 1) == 1L) res = res * ar % p
        ar = ar * ar % p
        nr = nr shr 1
    }
    return res
}
fun modinv(a: Long, p: Long = MOD): Long = modpow(a, p - 2, p)
fun ncr(n: Long, r: Long): Long {
    var a = 1L
    var b = 1L
    for (i in 1..r) {
        a = a * (n + 1 - i) % MOD
        b = b * i % MOD
    }
    return modinv(b, MOD) * a % MOD
}

class Combination(private val max: Long) {
    private val fac = longAry(max)
    private val finv = longAry(max)
    private val inv = longAry(max)
    private val p = MOD
    fun init() {
        fac[0] = 1
        fac[1] = 1
        finv[0] = 1
        finv[1] = 1
        inv[1] = 1
        for (i in 2 until max) {
            fac[i] = fac[i - 1] * i % p
            inv[i] = p - inv[p % i] * (p / i) % p;
            finv[i] = finv[i - 1] * inv[i] % p
        }
    }

    fun com(n: Long, r: Long): Long = if (n < r || (n < 0 || r < 0)) 0L else fac[n] * (finv[r] * finv[n - r] % p) % p
}

class Permutation(private val n: Long, private var searched: Long = 0L, private var nextIndex: Long = 0L) {
    private val size = fact(n)
    private val permList = longAry2(size, n)

    private tailrec fun fact(n: Long, ans: Long = 1L): Long {
        return if (n == 0L) ans
        else fact(n - 1, ans * n)
    }

    fun init() {
        create(0, longAry(n), boolAry(n))
    }

    private fun create(num: Long, list: LongArray, flag: Array<Boolean>) {
        if (num == n) {
            permList[searched] = list.copyOf()
            searched++
        }
        for (i in 0 until n) {
            if (flag[i]) continue
            list[num] = i
            flag[i] = true
            create(num + 1, list, flag)
            flag[i] = false
        }
    }

    fun hasNext(): Boolean {
        return if (nextIndex < size) {
            true
        } else {
            nextIndex = 0
            false
        }
    }

    fun nextPerm(): LongArray = permList[nextIndex++]
}

// Graph
data class Node(val id: Long, var past: Long = -1, val edges: MutableList<Edge> = mutableListOf())
data class Edge(val from: Long, val to: Long, val cost: Long = 1L)

fun dfs(nodes: Array<Node>, now: Long, seen: Array<Boolean>) {
    seen[now] = true
    for (edge in nodes[now].edges) {
        if (seen[edge.to]) continue
        dfs(nodes, edge.to, seen)
    }
}

fun bfs(nodes: Array<Node>, start: Long): LongArray {
    val queue = ArrayDeque<Long>()
    queue.add(start)
    val dist = longAry(nodes.size.toLong(), -1L)
    dist[start] = 0L
    while (queue.isNotEmpty()) {
        val now = queue.poll()
        for (edge in nodes[now].edges) {
            if (dist[edge.to] != -1L) continue
            dist[edge.to] = dist[now] + 1
            queue.add(edge.to)
        }
    }
    return dist
}

fun dijkstra(nodes: Array<Node>, start: Long): LongArray {
    val queue = PriorityQueue(16) { e1: Edge, e2: Edge ->
        return@PriorityQueue when {
            e1.cost < e2.cost -> -1
            e2.cost > e1.cost -> 1
            else -> 0
        }
    }
    queue.add(Edge(start, start, 0L))
    val dist = longAry(nodes.size.toLong(), INF / 2)
    dist[start] = 0
    while (queue.isNotEmpty()) {
        val now = queue.poll()
        if (dist[now.to] < now.cost) continue;
        for (edge in nodes[now.to].edges) {
            if (dist[edge.to] <= dist[edge.from] + edge.cost) continue
            dist[edge.to] = dist[edge.from] + edge.cost
            queue.add(Edge(edge.from, edge.to, dist[edge.to]))
            nodes[edge.to].past = edge.from
        }
    }
    return dist
}

// Data Structure
class UnionFind(size: Long) {
    private val par = LongArray(size.toInt()) { it.toLong() }
    private val size = longAry(size, 1L)
    fun root(x: Long): Long {
        return if (par[x] == x) {
            x
        } else {
            par[x] = root(par[x])
            par[x]
        }
    }

    fun same(x: Long, y: Long): Boolean = root(x) == root(y)
    fun unite(x: Long, y: Long) {
        var a = root(x)
        var b = root(y)
        if (a == b) return
        if (size[a] < size[b]) {
            var tmp = a
            a = b
            b = tmp
        }
        size[a] += size[b]
        par[b] = a
    }

    fun size(x: Long): Long = size[root(x)]
}

class SegmentTree(
    private val a: LongArray,
    private val op: (Long, Long) -> Long,
    private val def: Long = 0,
    private val size: Int = a.size,
    private val n: Int = Integer.highestOneBit(size) shl 1
) {
    private val nodes = longAry(2L * n - 1, def)

    fun init() {
        for (i in 0 until size) nodes[i + n - 1] = a[i]
        for (i in n - 2 downTo 0) nodes[i] = calc(nodes[2 * i + 1], nodes[2 * i + 2], op)
    }

    fun update(x: Long, value: Long) {
        var index = x + n - 1
        nodes[index] = value
        while (index > 0) {
            index = (index - 1) / 2
            nodes[index] = calc(nodes[2 * index + 1], nodes[2 * index + 2], op)
        }
    }

    fun get(a: Long, b: Long) = getSub(a, b, 0L, 0L, n.toLong())
    private fun getSub(a: Long, b: Long, k: Long, l: Long, r: Long): Long {
        return when {
            r <= a || b <= l -> def
            a <= l && r <= b -> nodes[k]
            else -> {
                val vl = getSub(a, b, k * 2 + 1, l, (l + r) / 2)
                val vr = getSub(a, b, k * 2 + 2, (l + r) / 2, r)
                calc(vl, vr, op)
            }
        }
    }

    fun joinToString(separator: String) = nodes.drop(n - 1).take(size).joinToString(separator)
}

// Scanner
class FastScanner {
    private val sin: InputStream = System.`in`
    private val buffer: ByteArray = ByteArray(1024) { 0 }
    private var ptr = 0
    private var buflen = 0

    private fun hasNextByte(): Boolean {
        return when {
            ptr < buflen -> true
            else -> {
                ptr = 0
                buflen = sin.read(buffer)
                buflen > 0
            }
        }
    }

    private fun readByte(): Int {
        return when {
            hasNextByte() -> buffer[ptr++].toInt()
            else -> -1
        }
    }

    private fun isPrintableChar(c: Int) = c in 33..126

    fun hasNext(): Boolean {
        while (hasNextByte() && !isPrintableChar(buffer[ptr].toInt())) ptr++
        return hasNextByte()
    }

    fun next(): String {
        if (!hasNext()) throw NoSuchElementException()
        val sb = StringBuilder()
        var b = readByte()
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b)
            b = readByte()
        }
        return sb.toString()
    }

    fun nextLong(): Long {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0L
        var minus = false
        var b = readByte()
        if (b.toChar() == '-') {
            minus = true
            b = readByte()
        }
        if (b.toChar() !in '0'..'9') throw NumberFormatException()
        while (true) {
            when {
                b.toChar() in '0'..'9' -> {
                    n *= 10
                    n += b.toChar() - '0'
                }
                b == -1 || !isPrintableChar(b) -> return if (minus) -n else n
                else -> throw NumberFormatException()
            }
            b = readByte()
        }
    }

//    "The world doesn't need you."
//
//    fun nextInt(): Int {
//        val nl = nextLong()
//        if (nl !in Int.MIN_VALUE..Int.MAX_VALUE) throw NumberFormatException()
//        return nl.toInt()
//    }
}
