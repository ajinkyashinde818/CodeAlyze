import java.util.*
import java.io.*

val pw = PrintWriter(System.out)
val MOD = 1000000007L
val INF = 2147483647
val LINF = 9223372036854775807L

fun main(args: Array<String>){
    solve()
    pw.flush()    
}

fun solve(){
    val s = next()
    val t = next()
    val ary1 = Array(s.length) { ' ' }
    val ary2 = Array(t.length) { ' ' }
    for (i in s.indices) {
        ary1[i] = s[i]
    }
    for (i in t.indices) {
        ary2[i] = t[i]
    }
    val list1 = ary1.sorted()
    val list2 = ary2.sortedDescending()
    var ans1 = ""
    var ans2 = ""
    for (i in list1) {
        ans1 += i
    }
    for (i in list2) {
        ans2 += i
    }
    if(ans1.compareTo(ans2) < 0) println("Yes") else println("No")
    
    

}

// Print
fun println(v: String){
    pw.println(v)
}
fun print(v: String){
    pw.print(v)
}

// Read
fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun nextList() = next().split(" ").toMutableList()
fun nextIntList(index: Int = 0) = next().split(" ").map{ it.toInt() + index }.toMutableList()
fun nextLongList(index: Long = 0L) = next().split(" ").map{ it.toLong() + index }.toMutableList()
fun nextDoubleList() = next().split(" ").map{ it.toDouble() }.toMutableList()
fun nextAryln(n: Int) = Array(n){ next() }
fun nextIntAryln(n: Int, index: Int = 0) = IntArray(n){ nextInt() + index }
fun nextLongAryln(n: Int, index: Long = 0) = LongArray(n){ nextLong() + index }
fun nextDoubleAryln(n: Int) = DoubleArray(n) { nextDouble() }

// Array
fun ary(n: Int, init: String = "") = Array(n) { init }
fun intAry(n: Int, init: Int = 0) = IntArray(n) { init }
fun longAry(n: Int, init: Long = 0L) = LongArray(n) { init }
fun doubleAry(n: Int, init: Double = 0.0) = DoubleArray(n) { init }
fun ary2(n: Int, m: Int, init: String = "") = Array(n) { Array(m) { init } }
fun intAry2(n: Int, m: Int, init: Int = 0) = Array(n) { IntArray(m) { init } }
fun longAry2(n: Int, m: Int, init: Long = 0) = Array(n) { LongArray(m) { init } }
fun doubleAry2(n: Int, m: Int, init: Double = 0.0) = Array(n) { DoubleArray(m) { init } }
fun ary3(n: Int, m: Int, k: Int, init: String = "") = Array(n) { Array(m) { Array(k) { init } } }
fun intAry3(n: Int, m: Int, k: Int, init: Int = 0) = Array(n) { Array(m) { IntArray(k) { init } } }
fun longAry3(n: Int, m: Int, k: Int, init: Long = 0L) = Array(n) { Array(m) { LongArray(k) { init } } }
fun doubleAry3(n: Int, m: Int, k: Int, init: Double = 0.0) = Array(n) { Array(m) { DoubleArray(k) { init } } }


// Math
fun abs(n: Int) : Int = Math.abs(n)
fun abs(n: Long) : Long = Math.abs(n)
fun abs(n: Double) : Double = Math.abs(n)
fun max(a: Int = -INF, b: Int = -INF, c: Int = -INF, d: Int = -INF, e: Int = -INF): Int = listOf(a, b, c, d, e).max()!!
fun max(a: Long = -LINF, b: Long = -LINF, c: Long = -LINF, d: Long = -LINF, e: Long = -LINF): Long = listOf(a, b, c, d, e).max()!!.toLong()
fun min(a: Int = INF, b: Int = INF, c: Int = INF, d: Int = INF, e: Int = INF): Int = listOf(a, b, c, d, e).min()!!
fun min(a: Long = LINF, b: Long = LINF, c: Long = LINF, d: Long = LINF, e: Long = LINF): Long = listOf(a, b, c, d, e).min()!!.toLong()
fun prime(from: Long, to: Long = from) : List<Long>{
    return (from..to).filter{ i ->
        val max = Math.sqrt(i.toDouble()).toLong()
        (2..max).all{ j -> i % j != 0L}
    }
}
fun gcd(a: Long, b: Long) : Long = if(a % b == 0L) b else gcd(b, (a % b))
fun lcm(a: Long, b: Long) : Long = a / gcd(a, b) * b
fun modpow(a: Long, n: Long, p:Long = MOD) : Long {
    var res = 1L
    var ar = a
    var nr = n
    while(nr > 0){
        if((nr and 1) == 1L) res = res * ar % p
        ar = ar * ar % p
        nr = nr shr 1
    }
    return res
}
fun modinv(a: Long, p: Long = MOD) : Long = modpow(a, p - 2, p)
fun ncr(n: Long, r: Long) : Long {
    var a = 1L
    var b = 1L
    for (i in 1..r) {
        a = a * (n + 1 - i) % MOD
        b = b * i % MOD
    }
    return modinv(b, MOD) * a % MOD
}

class Permutation(val n: Int, var searched: Int = 0, var nextIndex: Int = 0){
    val size = fact(n)
    val permList = Array(size) { IntArray(n){ 0 } }

    fun fact(n: Int) : Int = if(n == 0) 1 else n * fact(n - 1)
    fun init(){
        create(0, IntArray(n) { 0 }, Array<Boolean>(n){ false })
    }
    fun create(num: Int, list: IntArray, flag: Array<Boolean>){
        if(num == n){
            permList[searched] = list.copyOf()
            searched++
        }
        for (i in 0 until n) {
            if(flag[i]) continue
            list[num] = i
            flag[i] = true
            create(num + 1, list, flag)
            flag[i] = false
        }
    }
    fun hasNext() : Boolean {
        if(nextIndex < size){
            return true
        } else {
            nextIndex = 0
            return false
        }
    }
    fun nextPerm() : IntArray = permList[nextIndex++]
}
