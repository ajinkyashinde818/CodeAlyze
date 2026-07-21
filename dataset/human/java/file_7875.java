import java.io.PrintWriter

fun main() = abc167d()

@OptIn(ExperimentalStdlibApi::class)
fun abc167d() = IO_abc167d().exec {
    val (n, k) = readLongList(2).let { it[0].toInt() to it[1] }
    val aList = readIntList(n.toInt()).map { it - 1 }.toIntArray()

    val doubling = Array(62) { IntArray(n) }
    for ((index, to) in aList.withIndex()) doubling[0][index] = to

    for (p in 1..61) for (cu in 0 until n)
        doubling[p][cu] = doubling[p - 1][doubling[p - 1][cu]]

    var currIndex = 0

    for (p in 61 downTo 0) {
        if (k and (1L shl p) != 0L) currIndex = doubling[p][currIndex]
    }

    println(currIndex + 1)
}

//region
@Suppress("unused", "ClassName", "SpellCheckingInspection", "ConvertToStringTemplate")
private class IO_abc167d {
    private val input = System.`in`
    private val buffer = ByteArray(1024)
    private var pointer = 0
    private var bufferLength = 0
    private val pw = PrintWriter(System.out)
    private fun Byte.isPrintable() = this in 33..126
    private fun Byte.isNumeric() = this in '0'.toByte()..'9'.toByte()
    private fun Byte.toNumVal() =
        if (this.isNumeric()) this - '0'.toByte() else error(this.toString() + " is not numeric")

    private fun hasNextByte(): Boolean {
        return if (pointer < bufferLength) true else {
            pointer = 0
            bufferLength = input.read(buffer)
            bufferLength > 0
        }
    }

    private fun readByte(): Byte = if (hasNextByte()) buffer[pointer++] else -1
    private fun skipUnprintable() = run { while (hasNextByte() && !buffer[pointer].isPrintable()) pointer++ }
    private fun hasNext(): Boolean = run { skipUnprintable() }.run { hasNextByte() }
    private fun hasNextOrError() = if (!hasNext()) error("has no next element.") else Unit

    fun readString(): String {
        hasNextOrError()
        val sb = StringBuilder()
        var b = readByte()
        while (b.isPrintable()) {
            sb.appendCodePoint(b.toInt())
            b = readByte()
        }
        return sb.toString()
    }

    fun readLong(): Long {
        hasNextOrError()
        var n = 0L
        var negative = false
        var b = readByte()
        if (b == '-'.toByte()) {
            negative = true
            b = readByte()
        }
        if (!b.isNumeric()) error(b.toString() + " is not numeric.")
        while (true) {
            when {
                b.isNumeric() -> n = n * 10 + b.toNumVal()
                b.toInt() == -1 || !b.isPrintable() -> return if (negative) -n else n
                else -> error("failed to parse. [n=" + n + ", b=" + b + "]")
            }
            b = readByte()
        }
    }

    fun readInt() = readLong()
        .let { if (it in Int.MIN_VALUE..Int.MAX_VALUE) it.toInt() else error(it.toString() + " is not in range of Int.") }

    fun readDouble(): Double {
        var n = 0.0
        var div = 1.0
        var negative = false
        var b = readByte()
        if (b == '-'.toByte()) {
            negative = true
            b = readByte()
        }
        do n = n * 10 + b.toNumVal()
        while (run { b = readByte() }.run { b.isNumeric() })
        if (b == '.'.toByte()) {
            while (run { b = readByte() }.run { b.isNumeric() })
                n += b.toNumVal() / (run { div *= 10 }.run { div })
        }
        return if (negative) -n else n
    }

    fun readStringList(size: Int) = readList(size) { readString() }
    fun readIntList(size: Int) = readList(size) { readInt() }
    fun readLongList(size: Int) = readList(size) { readLong() }
    fun readDoubleList(size: Int) = readList(size) { readDouble() }
    fun readIntArray(size: Int) = IntArray(size) { readInt() }
    fun readLongArray(size: Int) = LongArray(size) { readLong() }
    fun readDoubleArray(size: Int) = DoubleArray(size) { readDouble() }
    inline fun <reified T> readArray(size: Int, init: () -> T) = Array(size) { init() }
    inline fun <T> readList(size: Int, init: () -> T) = List(size) { init() }
    fun println() = pw.println()
    fun print(o: Any?) = pw.print(o)
    fun println(o: Any?) = pw.println(o)
    fun exec(code: IO_abc167d.() -> Unit) = run { code() }.run { pw.flush() }
}
// endregion
