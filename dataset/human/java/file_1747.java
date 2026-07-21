import java.io.PrintWriter
import kotlin.math.pow

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun nextList() = next().split(" ")
fun nextIntList() = nextList().map(String::toInt)
fun nextLongList() = nextList().map(String::toLong)
fun nextDoubleList() = nextList().map(String::toDouble)

val pw = PrintWriter(System.out)
fun print(s: Any = "") = pw.print(s)
fun println(s: Any = "") = pw.println(s)

fun <T> Iterable<T>.join(separator: CharSequence = ", ", prefix: CharSequence = "", postfix: CharSequence = "") = joinToString(separator, prefix, postfix)
fun <T> Array<T>.join(separator: CharSequence = ", ", prefix: CharSequence = "", postfix: CharSequence = "") = joinToString(separator, prefix, postfix)
fun Int.pow(n: Int) = pow(n.toLong())
fun Int.pow(n: Long) = toDouble().pow(n.toDouble()).toLong()
fun Long.pow(n: Int) = pow(n.toLong())
fun Long.pow(n: Long) = toDouble().pow(n.toDouble()).toLong()

fun main(args: Array<String>) {
    main()
    pw.flush()
}

fun main() {
    val N = nextInt()
    val S = next().groupBy { it }.mapValues { it.value.size }
    val A = S.count { it.value == 1 }
    var ans = MInt(2).pow(A)
    for ((_, v) in S) {
        if (v == 1) continue
        ans *= (v + 1)
    }
    println(ans - 1)
}

class MInt {
    private val MOD = 1000000007L
    var v: Long

    constructor(v: Long) {
        this.v = v % MOD
    }

    constructor(v: Int) {
        this.v = v.toLong() % MOD
    }

    operator fun plus(b: MInt): MInt {
        val a = MInt(v)
        a.v += b.v
        if (a.v >= MOD) a.v -= MOD
        return a
    }

    operator fun plus(b: Int) = plus(MInt(b))
    operator fun plus(b: Long) = plus(MInt(b))

    operator fun minus(b: MInt): MInt {
        val a = MInt(v)
        a.v -= b.v
        if (a.v < 0) a.v += MOD
        return a
    }

    operator fun minus(b: Int) = minus(MInt(b))
    operator fun minus(b: Long) = minus(MInt(b))

    operator fun times(b: Int) = times(MInt(b))
    operator fun times(b: Long) = times(MInt(b))
    operator fun times(b: MInt): MInt {
        val a = MInt(v)
        a.v *= b.v
        a.v %= MOD
        return a
    }

    operator fun div(b: MInt): MInt {
        return MInt(v) * b.inv()
    }

    fun inv(): MInt {
        var a = v
        var b = MOD
        var u = 1L
        var w = 0L
        while (b != 0L) {
            val t = a / b
            a -= t * b
            u -= t * w
            var tmp = a
            a = b
            b = tmp
            tmp = u
            u = w
            w = tmp
        }
        u %= MOD
        if (u < 0) u += MOD
        return MInt(u)
    }

    fun pow(N: Int) = pow(N.toLong())

    fun pow(N: Long): MInt {
        var ans = MInt(1)
        var a = this
        var n = N
        while (n > 0) {
            if (n.and(1) == 1L) {
                ans *= a
            }
            a *= a
            n = n.shr(1)
        }
        return ans
    }

    override fun toString(): String {
        return v.toString()
    }
}
