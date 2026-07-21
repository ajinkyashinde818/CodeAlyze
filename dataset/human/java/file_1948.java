import java.io.PrintWriter
import java.util.*
import java.math.*
import java.lang.*

val pw = PrintWriter(System.out)
val MOD: Long = (1e+9 + 7).toLong()
val PROBLEM_NUM = 10 

fun main(args: Array<String>) {
    val (d, g) = readListOfInt()
    val p = mutableListOf<Int>()
    val c = mutableListOf<Int>()
    for(i in 0 until d) {
        val (p_, c_) = readListOfInt()
        p.add(p_)
        c.add(c_)
    }

    var ans = Int.MAX_VALUE
    for(mask in 0 until (1 shl d)) { // どれを最大まで取るかの全探索
        var (score, num, restMax) = Triple(0, 0, 0)
        for(i in 0 until d) {
            if(mask shr i and 1 == 1) { //全部足し合わせる
                score +=  100 * (i+1) * p[i] + c[i]
                num += p[i]
            } else {
                restMax = i + 1
            }
        }
        if(score < g) { // 全部突っ込んだ奴の総計で目標値に足りなければ
            val restScore = 100 * restMax
            val need = Math.ceil( (g - score).toDouble() / restScore ).toInt()
            if(need >= p[restMax-1]) continue // 必要数が足りなければ次にいく
            num += need
        }
        ans = Math.min(ans, num)
    }
    println(ans)
    pw.flush()
}

/****** Decrared Functions and Data Structures ******/
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
            v[i][j] = (v[i-1][j-1] + v[i-1][j] % MOD)
        }
    }
    return v.map { it.toList() }.toList()
}

fun gcd(a: Long, b: Long): Long = 
    if(b != 0L) a else gcd(b, a % b)

fun lcm(a: Long, b: Long) = 
    if(b==0L) a else gcd(b, a % b)

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

fun isDecimal(v: Double): Boolean = ((v - Math.floor(v)) != 0.0)

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
