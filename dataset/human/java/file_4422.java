import java.io.PrintWriter
import java.util.*
import java.math.*
import java.lang.*
import kotlin.comparisons.*

val pw = PrintWriter(System.out)
val MOD: Long = (1e+9 + 7).toLong()

fun main(args: Array<String>) {
    val n = readInt()

    val a = readListOfInt().map { it-1 }
    val b = readListOfInt()
    val c = readListOfInt()

    var sum = b[a[0]]
    for(i in 1 until n) {
        sum += b[a[i]]
        if(a[i-1]+1 == a[i]) {
            sum += c[a[i-1]]
        }
    }
    println(sum)
    pw.flush()
}

/****** Declared Functions and Data Structures ******/
// IO
fun read() = readLine()!!
fun readInt() = read().toInt()
fun readLong() = read().toLong()
fun readDouble() = read().toDouble()
fun readListOfString() = read().split(" ")
fun readListOfInt() = readListOfString().map { it.toInt() }
fun readListOfLong() = readListOfString().map { it.toLong() }
fun readListOfDouble() = readListOfString().map { it.toDouble() }

fun Double.format(digits: Int) = String.format("%.${digits}f", this)
fun Float.format(digits: Int) = String.format("%.${digits}f", this)

fun print(value: Any) { pw.print(value) }
fun println(value : Any) { pw.println(value) }


// Extensions
fun<T> List<T>.toBuckets(bucketKeys: List<T>): Map<T, Int> {
    val buckets = bucketKeys.associate { t -> Pair(t, 0) }.toMutableMap()
    this.forEach { t ->
        buckets[t] = buckets[t]!! + 1
    }
    return buckets
}

fun <K, V> Map<K, V>.toMutableMap(): MutableMap<K, V> = HashMap(this)

// Util Functions
fun<T> permutations(src: List<T>): List<List<T>> {
    if(src.size == 1) return listOf(src)
    val perms = mutableListOf<List<T>>()
    val insertElement = src[0]
    permutations(src.drop(1)).forEach { perm ->
        for(i in 0..perm.size) {
            val newPerm = perm.toMutableList()
            newPerm.add(i, insertElement)
            perms.add(newPerm.toList())
        }
    }
    return perms
}

// return nCr, if you want nCr, please access v[n][r]
fun combinations(n: Long): List<List<Long>> {
    val v = (0..n).map { (0..n).map{0L}.toMutableList() }.toMutableList()
    for(i in 0 until v.size) {
        v[i][0] = 1L
        v[i][i] = 1L
    }
    for(i in 0 until v.size) {
        for(j in 1 until i) {
            v[i][j] = (v[i-1][j-1] + v[i-1][j]) % MOD
        }
    }
    return v.map { it.toList() }.toList()
}

// should be a >= b
fun gcd(a: Long, b: Long): Long = 
    if(b == 0L) a else gcd(b, a % b)

// shoud be a >= b
fun lcm(a: Long, b: Long): Long = 
    a / gcd(a, b) * b

fun sumDigits(num_: Long): Long {
    var num = num_
    var rtn: Long = 0
    while(num != 0.toLong()) {
        val tmp = num % 10
        rtn += tmp
        num /= 10
    }
    return rtn
}

fun Double.isDecimal(): Boolean = ((this - Math.floor(this)) != 0.0)

// Data Structures
class Stack<T>(private var st: MutableList<T> = mutableListOf<T>()) {
    fun isEmpty() = st.isEmpty()
    fun top(): T = st.last()
    fun push(e: T) { st.add(e) }
    fun pop() { st = st.dropLast(1).toMutableList() }
}

class Queue<T>(private var que: MutableList<T> = mutableListOf<T>()) {
    fun isEmpty() = que.isEmpty()
    fun top(): T = que.first()
    fun push(e: T) { que.add(e) }
    fun pop() { que = que.drop(1).toMutableList() }
}
