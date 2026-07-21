import java.io.IOException
import java.io.InputStream
import java.io.PrintWriter
import java.util.NoSuchElementException

const val MOD = 1000000007

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    val m = sc.nextInt()
    val broken = BooleanArray(n + 1)
    sc.nextIntArray(m).forEach { broken[it] = true }
    val dp = LongArray(n + 1)
    dp[0] = 1
    for (i in 0..n - 2) {
        if (!broken[i + 1]) dp[i + 1] = (dp[i + 1] + dp[i]) % MOD
        if (!broken[i + 2]) dp[i + 2] = (dp[i + 2] + dp[i]) % MOD
    }
    dp[n] = (dp[n] + dp[n - 1]) % MOD
    println(dp[n])
}

class Scanner(private val `in`: InputStream) {
    private val buffer = ByteArray(1024)
    private var ptr = 0
    private var buflen = 0

    companion object {
        private fun isPrintableChar(b: Byte): Boolean = b in 33..126
        private fun isNumericChar(b: Byte): Boolean = b in 48..57
        private fun digit(b: Byte): Int = b - 48
    }

    fun hasNextByte(): Boolean {
        if (ptr < buflen) return true
        ptr = 0
        try {
            buflen = `in`.read(buffer)
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return 0 < buflen
    }

    private fun readByte(): Byte = if (hasNextByte()) buffer[ptr++] else -1

    private fun skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++
    }

    fun hasNext(): Boolean {
        skipUnprintable()
        return hasNextByte()
    }

    fun next(): String {
        if (!hasNext()) throw NoSuchElementException()
        return buildString {
            var b = readByte()
            while (isPrintableChar(b)) {
                appendCodePoint(b.toInt())
                b = readByte()
            }
        }
    }

    fun nextInt(): Int {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0
        var b = readByte()
        val minus = b.toChar() == '-'
        if (minus) b = readByte()
        if (!isNumericChar(b)) throw NumberFormatException()
        do {
            n *= 10
            n += digit(b)
            b = readByte()
        } while (isNumericChar(b))
        return if (minus) -n else n
    }

    fun nextInts(n: Int): Array<Int> = Array(n) { nextInt() }

    fun nextIntArray(n: Int): IntArray = IntArray(n) { nextInt() }

    fun nextIntArrays(n: Int, m: Int): Array<IntArray> {
        val arrays = Array(m) { IntArray(n) }
        repeat(n) { i -> repeat(m) { j -> arrays[j][i] = nextInt() } }
        return arrays
    }

    fun nextLong(): Long {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0L
        var b = readByte()
        val minus = b.toChar() == '-'
        if (minus) b = readByte()
        if (!isNumericChar(b)) throw NumberFormatException()
        do {
            n *= 10
            n += digit(b)
            b = readByte()
        } while (isNumericChar(b))
        return if (minus) -n else n
    }

    fun nextLongs(n: Int): Array<Long> = Array(n) { nextLong() }

    fun nextLongArray(n: Int): LongArray = LongArray(n) { nextLong() }

    fun nextLongArrays(n: Int, m: Int): Array<LongArray> {
        val arrays = Array(m) { LongArray(n) }
        repeat(n) { i -> repeat(m) { j -> arrays[j][i] = nextLong() } }
        return arrays
    }

}
