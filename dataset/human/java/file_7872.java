import java.io.IOException
import java.io.InputStream
import java.util.NoSuchElementException

val scanner = FastScanner()

fun main() {
    val N = scanner.nextInt()
    val K = scanner.nextLong()
    val A = scanner.readIntArray(N).map { it - 1 }
    val visitedA = IntArray(N)

    var current = 0
    var shuuki = 0
    var currentTime = 0
    var flag = false
    for (i in 1..N) {
        current = A[current]

        if (i >= K) {
            flag = true
            break
        }

        if (visitedA[current] != 0) {
            shuuki = i - visitedA[current]
            currentTime = i
            break
        }

        visitedA[current] = i
    }

    if (!flag) {
        val amari = (K - currentTime) % shuuki
        for (i in 0 until amari) {
            current = A[current]
        }
    }

    println(current + 1)
}

@Suppress("MemberVisibilityCanBePrivate")
class FastScanner {
    private val `in`: InputStream = System.`in`
    private val buffer = ByteArray(1024)
    private var ptr = 0
    private var buflen = 0
    private fun hasNextByte(): Boolean {
        if (ptr < buflen) {
            return true
        } else {
            ptr = 0
            try {
                buflen = `in`.read(buffer)
            } catch (e: IOException) {
                e.printStackTrace()
            }
            if (buflen <= 0) {
                return false
            }
        }
        return true
    }

    private fun readByte(): Int {
        return if (hasNextByte()) buffer[ptr++].toInt() else -1
    }

    operator fun hasNext(): Boolean {
        while (hasNextByte() && !isPrintableChar(buffer[ptr].toInt())) ptr++
        return hasNextByte()
    }

    operator fun next(): String {
        if (!hasNext()) throw NoSuchElementException()

        return buildString {
            var b = readByte()

            while (isPrintableChar(b)) {
                appendCodePoint(b)
                b = readByte()
            }
        }
    }

    fun nextLong(): Long {
        if (!hasNext()) throw NoSuchElementException()
        var n: Long = 0
        var minus = false
        var b = readByte()

        if (b == '-'.toInt()) {
            minus = true
            b = readByte()
        }

        if (b < '0'.toInt() || '9'.toInt() < b) {
            throw NumberFormatException()
        }

        while (true) {
            if ('0'.toInt() <= b && b <= '9'.toInt()) {
                n *= 10
                n += b - '0'.toInt().toLong()
            } else if (b == -1 || !isPrintableChar(b)) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }

            b = readByte()
        }
    }

    fun nextInt(): Int {
        val nl = nextLong()
        if (nl < Int.MIN_VALUE || nl > Int.MAX_VALUE) throw NumberFormatException()
        return nl.toInt()
    }

    fun nextDouble(): Double {
        return next().toDouble()
    }

    fun readIntArray(n: Int): IntArray {
        val arr = IntArray(n)

        for (i in 0 until n) {
            arr[i] = nextInt()
        }

        return arr
    }

    companion object {
        private fun isPrintableChar(c: Int): Boolean {
            return c in 33..126
        }
    }
}

inline fun IntArray.map(transform: (Int) -> Int): IntArray {
    for (i in indices) {
        this[i] = transform(this[i])
    }

    return this
}
