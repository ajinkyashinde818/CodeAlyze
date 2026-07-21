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
        val k = sc.nextInt()
        val l = sc.nextInt()

        val pq = Array(k) { sc.nextInt() - 1 to sc.nextInt() - 1 }
        val lr = Array(l) { sc.nextInt() - 1 to sc.nextInt() - 1 }

        // 道路でつながっているか
        val uf1 = UnionFind(n)
        pq.forEach {
            uf1.unite(it.first, it.second)
        }

        // 鉄道で繋がっているか
        val uf2 = UnionFind(n)
        lr.forEach {
            uf2.unite(it.first, it.second)
        }

        val map = mutableMapOf<Pair<Int, Int>, Int>()

        for (i in 0 until n) {
            val p = uf1.find(i) to uf2.find(i)
            map[p] = (map[p] ?: 0) + 1
        }

        println((0 until n).map {
            val p = uf1.find(it) to uf2.find(it)
            map[p]
        }.joinToString(" "))
    }
}

class UnionFind(private val v: Int) {
    // 頂点iの親 par[i] == iなら iは根
    private val par = Array(v) { it }
    // iを根とする部分木のサイズ
    private val size = Array(v) { 1 }

    // iが含まれる木の根
    fun find(i: Int): Int = if (par[i] == i) i else find(par[i])

    // xとyが同じグループに含まれるか?
    fun same(x: Int, y: Int) = find(x) == find(y)

    // iが含まれるグループのサイズ
    fun getSize(i: Int) = size[find(i)]

    // xとyを繋げる 元から同じグループならfalse
    fun unite(x: Int, y: Int): Boolean {
        val rootX = find(x)
        val rootY = find(y)

        if (rootX == rootY) return false

        // データ構造をマージする一般的なテク
        if (size[rootX] > size[rootY]) {
            par[rootY] = rootX
            size[rootX] += size[rootY]
        } else {
            par[rootX] = rootY
            size[rootY] += size[rootX]
        }

        return true
    }
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
