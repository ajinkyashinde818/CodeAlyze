import kotlin.math.sqrt

fun main() {
    var n = nextLong()
    val primeCounts = mutableMapOf<Long, Int>()
    val sieve = sizedArray(sqrt(n.toDouble()).toInt() + 1, true)
    sieve[0] = false
    sieve[1] = false
    sieve.indices.forEach {
        if (!sieve[it]) return@forEach
        // check gcd
        while (n % it == 0L) {
            n /= it
            primeCounts[it.toLong()] = primeCounts.getOrDefault(it.toLong(), 0) + 1
        }
        // update sieve
        var index = it + it
        while (index <= sieve.lastIndex) {
            sieve[index] = false
            index += it
        }
    }
    if (n >= sieve.size) {
        primeCounts[n] = 1
    }
    var res = 0
    primeCounts.forEach { _, value ->
        var count = value
        var num = 1
        while (num <= count) {
            count -= num
            num++
            res++
        }
    }
    println(res)
}

// # Utils
// ## Input
fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun nextList() = next().split(" ")
fun nextIntList() = next().split(" ").map(String::toInt)
fun nextLongList() = next().split(" ").map(String::toLong)
fun nextDoubleList() = next().split(" ").map(String::toDouble)

// ## Array
inline fun <reified T> sizedArray(size: Int, default: T) = Array(size) { default }

// ## mod^-1
//    [NOTE] CANNOT use this for 0, mod, 2mod, 3mod ...(return wrong value)
fun modinv(num: Long, mod: Long): Long {
    var a = num
    var b = mod
    var u = 1L
    var v = 0L
    while (b > 0) {
        val t = a.div(b)
        a -= t * b
        a = b.also { b = a } // swap a and b
        u -= t * v
        u = v.also { v = u } // swap u and v
    }
    u %= mod
    if (u < 0) u += mod
    return u
}
