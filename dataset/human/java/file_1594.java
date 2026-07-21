import java.io.BufferedReader
import java.io.PrintWriter

var out: PrintWriter = PrintWriter(System.out)  // これを使って出力すると早い
fun main(args: Array<String>) {
    try {
        val nm = ReadLib.readIntArray()
        val aMap = ReadLib.readNTimesCharArray(nm[0])
        val bMap = ReadLib.readNTimesCharArray(nm[1])

        for (x in 0..(nm[0] - nm[1])) {
            for (y in 0..(nm[0] - nm[1])) {
                var isMatched = true
                for (cx in 0 until nm[1]) {
                    for (cy in 0 until nm[1]) {
                        if (aMap[x + cx][y + cy] != bMap[cx][cy]) {
                            isMatched = false
                            break
                        }
                        if (!isMatched) {
                            break
                        }
                    }
                }

                if (isMatched) {
                    out.println("Yes")
                    return
                }

            }
        }

        out.println("No")

    } finally {
        out.flush()   // 消さない
    }
}

/**
 * 読み取り
 */
class ReadLib {
    companion object {
        private var reader: BufferedReader = System.`in`.bufferedReader()

        fun reset() {
            reader = System.`in`.bufferedReader()
        }

        fun readInt(): Int {
            return Integer.parseInt(reader.readLine())
        }

        // Int
        fun readIntArray(delimiters: String = " "): IntArray {
            return reader
                .readLine()
                .split(delimiters)
                .map { s -> Integer.parseInt(s) }
                .toIntArray()
        }

        fun readNTimesInt(n: Int): IntArray {
            return (1..n).map { readInt() }.toIntArray()
        }

        fun readNTimesIntArray(n: Int): Array<IntArray> {
            return (1..n).map { readIntArray() }.toTypedArray()
        }

        // long
        // TODO 別の方法を考える
        fun readLong(): Long {
            return reader.readLine().toLong()
        }

        fun readLongArray(delimiters: String = " "): LongArray {
            return reader.readLine()
                .split(delimiters)
                .map { s -> s.toLong() }
                .toLongArray()
        }

        fun readNTimesLong(n: Int): LongArray {
            return (1..n).map { readLong() }.toLongArray()
        }

        fun readString(): String {
            return reader.readLine()
        }

        fun readStringArray(delimiters: String = " "): Array<String> {
            return readString().split(delimiters).toTypedArray()
        }

        fun readNTimesCharArray(n: Int): Array<CharArray> {
            return (1..n).map { readString().toCharArray() }.toTypedArray()
        }

        fun readNTimesString(n: Int): Array<String> {
            return (1..n).map { readString() }.toTypedArray()
        }

    }
}

/**
 * 要素とその個数を出力
 */
fun <T> Array<T>.ofCountMap(): Map<T, Int> {
    return this.groupBy { it }.mapValues { it.value.count() }
}

/**
 * 文字とその個数を出力
 */
fun String.ofCountMap(): Map<Char, Int> {
    return this.toCharArray().ofCountMap()
}

/**
 * 文字とその個数を出力
 */
fun CharArray.ofCountMap(): Map<Char, Int> {
    return this.groupBy { it }.mapValues { it.value.count() }
}

/**
 * Combination, nCk mod p を求める
 * https://ja.wikipedia.org/wiki/%E3%83%A2%E3%82%B8%E3%83%A5%E3%83%A9%E9%80%86%E6%95%B0
 * http://drken1215.hatenablog.com/entry/2018/06/08/210000
 * @param maxN 最大のn
 * @param mod 素数p
 */
class ModCombination(private val maxN: Int, private val mod: Int = 1000000007) {
    val fac: IntArray = IntArray(maxN)
    val finv: IntArray = IntArray(maxN)

    init {
        val inv: IntArray = IntArray(maxN)
        fac[0] = 1
        fac[1] = 1

        inv[0] = 1
        inv[1] = 1
        for (i in 2..maxN) {
            fac[i] = fac[i - 1] * i % mod   // 累積
            // mod % i < i
            inv[i] = mod - ((inv[mod % i].toLong()) * (mod / i) % mod).toInt()
            finv[i] = finv[i - 1] * inv[i] % mod
        }
    }

    /**
     * nCk mod p
     */
    fun Calc(n: Int, k: Int): Int {
        if (n < k || n < 0 || k < 0) {
            return 0
        }

        return ((fac[n].toLong() * finv[k] % mod) * finv[n - k] % mod).toInt()
    }
}
