import java.io.PrintWriter
import java.util.*

fun main(args: Array<String>) = IO().exec {
    val a = long()
    val b = long()
    val c = long()
    val p = Math.min(b, c)
    val q = Math.min(c - p, a)
    val r = if (c - p - q > 0) 1 else 0
    val s = b - p
    println(p * 2 + q + r + s)
}

class IO {
    val printable = 33..126
    val buffer = ByteArray(1024)
    var ptr = 0
    var buflen = 0
    val out = PrintWriter(System.out)
    fun hasNextByte(): Boolean {
        if (ptr < buflen) {
            return true
        } else {
            ptr = 0
            buflen = System.`in`.read(buffer)
            if (buflen <= 0) {
                return false
            }
        }
        return true
    }
    fun readByte(): Byte {
        return if (hasNextByte()) buffer[ptr++] else return -1
    }
    fun hasNext(): Boolean {
        while (hasNextByte() && buffer[ptr] !in printable) ptr++
        return hasNextByte()
    }
    fun string(): String {
        if (!hasNext()) throw NoSuchElementException()
        val sb = StringBuilder()
        var b = readByte()
        while (b in printable) {
            sb.appendCodePoint(b.toInt())
            b = readByte()
        }
        return sb.toString()
    }
    fun long(): Long {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0L
        var minus = false
        var b = readByte()
        if (b == '-'.toByte()) {
            minus = true
            b = readByte()
        }
        if (b !in '0'.toByte()..'9'.toByte()) {
            throw NumberFormatException()
        }
        while (true) {
            if (b in '0'.toByte()..'9'.toByte()) {
                n *= 10
                n += b - '0'.toByte()
            } else if (b == (-1).toByte() || b !in printable) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }
            b = readByte()
        }
    }
    fun int(): Int {
        val nl = long()
        if (nl !in Integer.MIN_VALUE..Integer.MAX_VALUE) throw NumberFormatException()
        return nl.toInt()
    }
    fun double(): Double {
        return string().toDouble()
    }
    fun print(obj: Any) = out.print(obj)
    fun print(i: Int) = out.print(i)
    fun print(l: Long) = out.print(l)
    fun println(obj: Any) = out.println(obj)
    fun println(i: Int) = out.println(i)
    fun println(l: Long) = out.println(l)
    inline fun exec(block: IO.() -> Unit) {
        block()
        out.flush()
    }
}
