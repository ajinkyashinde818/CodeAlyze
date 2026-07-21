import java.io.PrintWriter
import java.util.*
import java.math.*
import java.lang.*
import kotlin.comparisons.*

val pw = PrintWriter(System.out)
val MOD: Long = (1e+9 + 7).toLong()

fun main(args: Array<String>) {
    val (n, k, s) = readListOfInt()
    val sl = s.toLong()

    val ansArr = Array(n) { 0L }
    for(i in 0 until k) {
        ansArr[i] = sl
    }
    for(i in k until n) {
        ansArr[i] = if(sl > 10) sl / 2L + 1L else sl + 1L 
    }

    println(ansArr.joinToString(" "))
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
fun<T> List<T>.toBuckets(): Map<T, Int>
	= this.groupBy { it }.mapValues { it.value.size }

fun<T: Comparable<T>> List<T>.upperBound(element: T, fromIndex: Int=0, toIndex: Int=this.size): Int {
	var l = fromIndex
	var r = toIndex
	while(l < r) {
		val mid = (l+r) / 2
		if(element >= this[mid]) { 
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l
}

fun<T: Comparable<T>> List<T>.lowerBound(element: T, fromIndex: Int=0, toIndex: Int=this.size): Int {
	var l = fromIndex
	var r = toIndex
	while(l < r) {
		val mid = (l+r) / 2
		if(element <= this[mid]) { 
			r = mid
		} else {
			l = mid + 1
		}
	}
	return r 
}

fun <K, V> Map<K, V>.toMutableMap(): MutableMap<K, V> = HashMap(this)

// Util Functions
fun Long.makeDivisors(): List<Long> {
	val divisors = mutableListOf<Long>()
	for(i in 1L .. Math.sqrt(this.toDouble()).toLong()+1L) {
		if(this % i == 0L) {
			divisors.add(i)
			if(i != this/i) {
				divisors.add(this/i)
			}
		}
	}
	return divisors.distinct().sorted()
}

fun Long.isPrime(): Boolean {
	if(this==1L) return false
	for(i in 2L .. Math.sqrt(this.toDouble()).toLong() + 1L) {
		if(this % i == 0L && this != i) {
			return false
		}
	}
	return true
}


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

// return nCr % MOD
fun modCombinations(n: Int, k: Int, mod: Long): Long {
	val factorials = Array(n+1) { 0L }.apply {
		this[0] = 1L
		if(this.size > 1) this[1] = 1L
	}
	val inverses = Array(n+1) { 0L }.apply {
		this[0] = 1L
		if(this.size > 1) this[1] = 1L
	}
	val factorialInverses = Array(n+1) { 0L }.apply {
		this[0] = 1L
		if(this.size > 1) this[1] = 1L
	}
	for(i in 2 .. n) {
		factorials[i] = (factorials[i-1] * i.toLong() % mod)
		inverses[i] = (mod - inverses[mod.toInt() % i] * (mod / i.toLong()) % mod)
		factorialInverses[i] = (factorialInverses[i-1] * inverses[i] % mod)
	}

	return factorials[n] % mod * (factorialInverses[k] * factorialInverses[n-k] % mod) % mod
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
