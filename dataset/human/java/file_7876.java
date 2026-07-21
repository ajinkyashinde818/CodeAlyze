@file:Suppress("NOTHING_TO_INLINE", "EXPERIMENTAL_FEATURE_WARNING", "OVERRIDE_BY_INLINE")

import java.io.PrintWriter
import kotlin.math.*
import kotlin.random.Random
import kotlin.collections.sort as _sort
import kotlin.collections.sortDescending as _sortDescending
import kotlin.io.println as iprintln

/** @author Spheniscine */
fun main() { _writer.solve(); _writer.flush() }
fun PrintWriter.solve() {
    val n = readInt()
    val k = readLong()

    val A = IntArray(n) { readInt()-1 }

    val ans = run<Int> ans@{
        val H = IntList()
        val I = IntArray(n) { -1 }

        var i = 0
        var p = 0

        while(true) {
            if(i.toLong() == k) return@ans p
            H.add(p)
            if(I[p] == -1) {
                I[p] = i
                i++
                p = A[p]
            } else {
                val s = I[p]
                val x = s + ((k - s) % (i - s)).toInt()
                return@ans H[x]
            }
        }
        0
    } + 1

    println(ans)
}

class IntList(initialCapacity: Int = 12) {
    private var _arr = IntArray(initialCapacity)
    private val capacity get() = _arr.size
    var size = 0
        private set
    inline val lastIndex get() = size - 1
    inline val indices get() = 0 until size

    constructor(copyFrom: IntArray): this(copyFrom.size) { copyFrom.copyInto(_arr); size = copyFrom.size }
    constructor(copyFrom: Collection<Int>): this(copyFrom.size) { _arr = copyFrom.toIntArray(); size = copyFrom.size }

    fun contentEquals(other: IntList): Boolean {
        return this === other || size == other.size && indices.all { this[it] == other[it] }
    }

    private fun grow(minCapacity: Int = 8) {
        val newCapacity = maxOf(minCapacity, capacity + (capacity shr 1))
        _arr = _arr.copyOf(newCapacity)
    }

    fun ensureCapacity(minCapacity: Int) { if(capacity < minCapacity) grow(minCapacity) }

    operator fun get(index: Int): Int {
        require(index in 0 until size)
        return _arr[index]
    }

    operator fun set(index: Int, value: Int) {
        require(index in 0 until size)
        _arr[index] = value
    }

    fun add(value: Int) {
        if(size == capacity) grow()
        _arr[size++] = value
    }

    fun add(index: Int, element: Int) {
        if(size == capacity) grow()
        _arr.copyInto(_arr, index + 1, index, size)
        size++
        set(index, element)
    }

    fun clear() { size = 0 }

    fun removeAt(index: Int): Int {
        val e = get(index)
        _arr.copyInto(_arr, index, index + 1, size)
        size--
        return e
    }

    operator fun iterator() = object: IntIterator() {
        private var pos = 0
        override fun hasNext() = pos < size
        override fun nextInt() = get(pos++)
    }

    inline fun isEmpty() = size == 0
    inline fun isNotEmpty() = size != 0

    fun pop() = _arr[--size]

    fun swap(i: Int, j: Int) { val t = this[i]; this[i] = this[j]; this[j] = t }
    fun reverse() {
        for(i in 0 until size / 2) swap(i, lastIndex - i)
    }

    fun shuffle(rnd: Random = random) = _shuffle(rnd, _arr::get, _arr::set, size)
    fun sort() { shuffle(); _arr._sort(0, size) }
    fun sortDescending() { sort(); reverse() }

    fun joinToString(separator: CharSequence) = if(size == 0) "" else let {
        buildString {
            append(it[0])
            for (i in 1 until size) {
                append(separator).append(it[i])
            }
        }
    }

    override fun toString() = "[" + joinToString(", ") + "]"

    fun toIntArray() = _arr.copyOf(size)
    fun toList() = List(size, ::get)

    inline fun first() = get(0)
    inline fun last() = get(lastIndex)
}

inline fun IntList(size: Int, init: (Int) -> Int) = IntList(size).apply {
    for(i in 0 until size) { add(init(i)) }
}
inline fun IntArray.toIntList() = IntList(this)
inline fun Collection<Int>.toIntList() = IntList(this)
inline fun intListOf(vararg values: Int) = IntList(values)

fun IntList.max() = (1 until size).fold(this[0]) { acc, i -> max(acc, this[i]) }
fun IntList.min() = (1 until size).fold(this[0]) { acc, i -> min(acc, this[i]) }
fun IntList.getOrNull(i: Int) = if(i in indices) get(i) else null
inline fun IntList.count(predicate: (Int) -> Boolean) = indices.count { predicate(this[it]) }
fun IntList.copyOf() = IntList(size, ::get)

/** IO */
//@JvmField val INPUT = File("input.txt").inputStream()
//@JvmField val OUTPUT = File("output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _ln = ""
@JvmField var _lnPtr = 0
fun read(): String {
    while (_lnPtr >= _ln.length) {
        _ln = readLine() ?: return ""
        _lnPtr = 0
    }
    var j = _ln.indexOf(' ', _lnPtr)
    if(j < 0) j = _ln.length
    val res = _ln.substring(_lnPtr, j)
    _lnPtr = j + 1
    return res
}
fun readRem(): String /* reads remainder of current line */ =
    _ln.substring(min(_lnPtr, _ln.length)).also { _lnPtr = _ln.length }
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
