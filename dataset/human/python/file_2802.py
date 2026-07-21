import kotlin.math.sqrt

//

fun main() {
    abc169d()
}

fun abc169d() {
    val n = readLine()!!.toLong()
    val primes = mutableMapOf<Long, Long>()
    var t = n
    var i = 2L
    while (i * i <= t) {
        if (t % i == 0L) {
            primes[i] = 0L
            while (t % i == 0L) {
                t /= i
                primes[i] = primes[i]!! + 1
            }
        }
        i++
    }
    if (t != 1L) primes[t] = 1L
    var count = 0
    for (l in primes.values) {
        t = l
        for (j in 1 .. l) {
            t -= j
            if (t >= 0) {
                count++
            } else {
                break
            }
        }
    }
    println(count)
}
