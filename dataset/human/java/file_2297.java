@file:Suppress("NOTHING_TO_INLINE", "EXPERIMENTAL_FEATURE_WARNING", "OVERRIDE_BY_INLINE")
//@file:OptIn(ExperimentalStdlibApi::class)

import java.io.PrintWriter
import java.util.PriorityQueue
import kotlin.math.*
import kotlin.random.Random
import kotlin.collections.sort as _sort
import kotlin.collections.sortDescending as _sortDescending
import kotlin.io.println as iprintln


/** @author Spheniscine */
fun main() { _writer.solve(); _writer.flush() }
fun PrintWriter.solve() {
//    val startTime = System.nanoTime()

    val numCases = 1//readInt()
    case@ for(case in 1..numCases) {
//        print("Case #$case: ")

        val n = readInt()
        val q = readInt()
        val A = PropagatingSegmentTree(n)
        A.build { if(readInt() == 1) Seg.one else Seg.zero }

        repeat(q) {
            val t = readInt()
            val l = readInt()-1
            val r = readInt()
            when(t) {
                1 -> A.update(l, r, true)
                2 -> println(A.query(l, r).inv)
            }
        }
    }

//    iprintln("Time: ${(System.nanoTime() - startTime) / 1000000} ms")
}

val Int.c2 get() = toLong() * minus(1) / 2

data class Seg(val num0: Int, val num1: Int, val inv: Long) {
    companion object {
        val identity = Seg(0, 0, 0)
        val zero = Seg(1, 0, 0)
        val one = Seg(0, 1, 0)
    }
    operator fun plus(b: Seg) = Seg(num0 + b.num0, num1 + b.num1, inv + b.inv + num1.toLong() * b.num0)
    operator fun not() = Seg(num1, num0, (num0 + num1).c2 - num0.c2 - num1.c2 - inv)
}

class PropagatingSegmentTree(
    val size: Int) {
    /* degenericization helpers */
    val identityValue: Seg = Seg.identity
    inline fun op(a: Seg, b: Seg): Seg = a + b
    inline val updateIdentity: Boolean get() = false
    inline fun composer(a: Boolean, b: Boolean): Boolean = a xor b
    inline fun updater(t: Seg, u: Boolean): Seg = if(u) !t else t

    private inline fun treeSize() = if(size == 0) 0 else Integer.highestOneBit(size.shl(2) - 1)

    @Suppress("UNCHECKED_CAST")
    private val tree = Array(treeSize()) { identityValue }
    @Suppress("UNCHECKED_CAST")
    private val lazy = BooleanArray(tree.size)// { updateIdentity } as Array<Boolean>

    fun build(list: List<Seg>) {
        if(size == 0) return
        build(list, 1, 0, size-1)
    }

    inline fun build(generator: (Int) -> Seg) { build(List(size) { generator(it) }) }

    private inline fun mid(low: Int, high: Int) = (low + high) shr 1
    private fun build(list: List<Seg>, node: Int, a: Int, b: Int) {
        if(a == b) {
            tree[node] = list[a]
            return
        }

        build(list, node shl 1, a, mid(a, b))
        build(list, node shl 1 or 1, 1 + mid(a, b), b)
        updateNode(node)
    }

    private inline fun updateNode(i: Int) {
        tree[i] = op(tree[i shl 1], tree[i shl 1 or 1])
    }

    fun update(start: Int, endx: Int, value: Boolean) {
        update(1, 0, size-1, start, endx-1, value)
    }
    fun update(range: IntRange, value: Boolean) {
        update(range.first, range.last + 1, value)
    }

    private inline fun updateLazy(i: Int, u: Boolean) {
        lazy[i] = composer(lazy[i], u)
    }

    private fun propagate(node: Int, a: Int, b: Int) {
        tree[node] = updater(tree[node], lazy[node])
        if(a != b) {
            updateLazy(node shl 1, lazy[node])
            updateLazy(node shl 1 or 1, lazy[node])
        }
        lazy[node] = updateIdentity
    }

    private fun update(node: Int, a: Int, b: Int, i: Int, j: Int, u: Boolean) {
        if(lazy[node] != updateIdentity) {
            propagate(node, a, b)
        }

        if(a > b || a > j || b < i) return

        if(a >= i && b <= j) {
            lazy[node] = u
            propagate(node, a, b)
            return
        }

        update(node shl 1, a, mid(a, b), i, j, u)
        update(node shl 1 or 1, 1 + mid(a, b), b, i, j, u)

        updateNode(node)
    }

    fun query(start: Int, endx: Int) =
        query(1, 0, size-1, start, endx-1)
    fun query(range: IntRange) =
        query(range.first, range.last+1)

    private fun query(node: Int, a: Int, b: Int, i: Int, j: Int): Seg {
        if(a > b || a > j || b < i) return identityValue
        if(lazy[node] != updateIdentity) {
            propagate(node, a, b)
        }

        if(a >= i && b <= j) {
            return tree[node]
        }

        val l = query(node shl 1, a, mid(a, b), i, j)
        val r = query(node shl 1 or 1, 1 + mid(a, b), b, i, j)

        return op(l, r)
    }

    val root get() = tree[1]
}

/** IO */
//@JvmField val INPUT = File("input.txt").inputStream()
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

const val _BUFFER_SIZE = 1 shl 16
@JvmField val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField var _bufferPt = 0
@JvmField var _bytesRead = 0

tailrec fun readChar(): Char {
    if(_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if(_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar()
        else c
    }
}

fun readLine(): String? {
    var c = readChar()
    return if(c == Char.MIN_VALUE) null
    else buildString {
        while(c != '\n' && c != Char.MIN_VALUE) {
            append(c)
            c = readChar()
        }
    }
}
fun readLn() = readLine()!!

fun read() = buildString {
    var c = readChar()
    while(c <= ' ') {
        if(c == Char.MIN_VALUE) return@buildString
        c = readChar()
    }
    do {
        append(c)
        c = readChar()
    } while(c > ' ')
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)

/** shuffles and sort overrides to avoid quicksort attacks */
private inline fun <T> _shuffle(rnd: Random, get: (Int) -> T, set: (Int, T) -> Unit, size: Int) {
    // Fisher-Yates shuffle algorithm
    for (i in size - 1 downTo 1) {
        val j = rnd.nextInt(i + 1)
        val temp = get(i)
        set(i, get(j))
        set(j, temp)
    }
}

@JvmField var _random: Random? = null
val random get() = _random ?: Random(0x594E215C123 * System.nanoTime()).also { _random = it }

fun IntArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun IntArray.sort() { shuffle(); _sort() }
fun IntArray.sortDescending() { shuffle(); _sortDescending() }

fun LongArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun LongArray.sort() { shuffle(); _sort() }
fun LongArray.sortDescending() { shuffle(); _sortDescending() }

fun DoubleArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
fun DoubleArray.sort() { shuffle(); _sort() }
fun DoubleArray.sortDescending() { shuffle(); _sortDescending() }

fun CharArray.shuffle(rnd: Random = random) = _shuffle(rnd, ::get, ::set, size)
inline fun CharArray.sort() { _sort() }
inline fun CharArray.sortDescending() { _sortDescending() }

inline fun <T: Comparable<T>> Array<out T>.sort() = _sort()
inline fun <T: Comparable<T>> Array<out T>.sortDescending() = _sortDescending()
inline fun <T: Comparable<T>> MutableList<out T>.sort() = _sort()
inline fun <T: Comparable<T>> MutableList<out T>.sortDescending() = _sortDescending()

fun `please stop removing these imports IntelliJ`() { iprintln(max(1, 2)) }

/** additional commons */
inline fun <T> Iterable<T>.sumByLong(func: (T) -> Long) = fold(0L) { acc, t -> acc + func(t) }
inline fun <T> Sequence<T>.sumByLong(func: (T) -> Long) = fold(0L) { acc, t -> acc + func(t) }
inline fun <T> Array<T>.sumByLong(func: (T) -> Long) = fold(0L) { acc, t -> acc + func(t) }
fun IntArray.sumLong() = fold(0L, Long::plus)
