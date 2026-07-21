import java.util.*
import kotlin.*

import java.io.InputStream
import java.lang.NumberFormatException
import java.lang.StringBuilder


fun main(args: Array<String>) {
    Program().solve()
}

class Program {
    fun solve() {
        val sc = FastScanner()
        val n = sc.nextInt()
        val s = sc.next()

        val cnt = Array(26) { 0 }
        for (i in 0 until n) cnt[s[i] - 'a']++
        var ans = ModInt(1)
        for(i in 0 until 26) ans *= cnt[i] + 1
        println(ans -1)
    }
}

class ModInt(_num: Number) : Number() {
    companion object {
        const val mod: Long = 1000000007L
    }

    private val num: Long = if (_num.toLong() < 0) (_num.toLong() % mod) + mod else _num.toLong() % mod
    operator fun plus(right: Number) = ModInt(num + (right.toLong() % mod))
    operator fun minus(right: Number) = ModInt(num - (right.toLong() % mod))
    operator fun times(right: Number) = ModInt(num * (right.toLong() % mod))

    // modが素数の時のみ
    operator fun div(right: Number) = this * ModInt(right).inverse()

    fun power(n: Number): ModInt {
        var a = this
        var result = ModInt(1)
        var tmp = n.toLong()
        while (tmp > 0) {
            if (tmp % 2 == 1L) {
                result *= a
            }
            tmp /= 2
            a *= a
        }
        return result
    }

    // modが素数のときのみ 逆元
    fun inverse(): ModInt {
        return power(mod - 2L)
    }

    override fun toString() = num.toString()
    override fun toInt() = num.toInt()
    override fun toLong() = num
    override fun toByte() = num.toByte()
    override fun toChar() = num.toChar()
    override fun toDouble() = num.toDouble()
    override fun toFloat() = num.toFloat()
    override fun toShort() = num.toShort()
}

class FastScanner {
    companion object {
        val input: InputStream = System.`in`
        val buffer = ByteArray(1024) { 0 }
        fun isPrintableChar(c: Int): Boolean = c in 33..126
    }

    var ptr = 0
    var buflen = 0
    private fun hasNextByte(): Boolean {
        if (ptr < buflen) {
            return true
        } else {
            ptr = 0
            buflen = input.read(buffer)
            if (buflen <= 0) {
                return false
            }
        }
        return true
    }

    private fun readByte(): Int = if (hasNextByte()) buffer[ptr++].toInt() else -1

    private fun skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr].toInt())) ptr++
    }

    fun hasNext(): Boolean {
        skipUnprintable()
        return hasNextByte()
    }

    fun next(): String {
        if (!hasNext()) throw NoSuchElementException()
        val sb = StringBuilder()
        var b = readByte()
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b)
            b = readByte()
        }
        return sb.toString()
    }

    fun nextInt(): Int {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0
        var b = readByte()
        // '-' = 45
        val minus = b == 45
        if (minus) {
            b = readByte()
        }

        // '0' = 48 '9' = 57
        if (b !in 48..57) {
            throw NumberFormatException()
        }

        while (true) {
            if (b in 48..57) {
                n *= 10
                n += b - 48
            } else if (b == -1 || !isPrintableChar(b)) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }
            b = readByte()
        }
    }

    fun nextLong(): Long {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0L
        var b = readByte()
        // '-' = 45
        val minus = b == 45
        if (minus) {
            b = readByte()
        }

        // '0' = 48 '9' = 57
        if (b !in 48..57) {
            throw NumberFormatException()
        }

        while (true) {
            if (b in 48..57) {
                n *= 10
                n += b - 48
            } else if (b == -1 || !isPrintableChar(b)) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }
            b = readByte()
        }
    }

    fun nextDouble(): Double = next().toDouble()
}
