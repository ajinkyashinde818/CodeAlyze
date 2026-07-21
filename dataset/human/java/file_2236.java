import java.lang.Math.sqrt

fun main() = Thread(null, ::abc169d, "(^o^)", 128 * 1024 * 1024).apply { start() }.join()

@OptIn(ExperimentalStdlibApi::class)
fun abc169d() {
    val n = readLine()!!.toLong()

    val primes = primeFactorization(n)

    val answer = primes.map {
        var count = it.value
        (1..1000).takeWhile { i ->
            count -= i
            count >= 0
        }.count()
    }.sum()

    println(answer)
}

private fun primeFactorization(n: Long): Map<Long, Long> {
    val factors = mutableMapOf<Long, Long>()
    var temp = n
    var i = 2L
    while (i * i <= temp) {
        while (temp % i == 0L) {
            factors[i] = (factors[i] ?: 0) + 1
            temp /= i
        }
        i++
    }
    if (temp > 1) factors[temp] = 1
    return factors
}
