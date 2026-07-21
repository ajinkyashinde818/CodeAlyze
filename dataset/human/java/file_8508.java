import java.io.PrintWriter

fun main(args: Array<String>) {
    PrintWriter(System.out).use { out ->
        solve(out)
        out.flush()
    }
}

fun solve(out: PrintWriter) {
    val (n, k ,l ) = readIntegerList()
    val uf1 = UnionFind(n)
    repeat(k) {
        val (p, q) = readIntegerList().map { it - 1 }
        uf1.unite(p, q)
    }

    val uf2 = UnionFind(n)
    repeat(l) {
        val (p, q) = readIntegerList().map { it - 1 }
        uf2.unite(p, q)
    }

    val map = mutableMapOf<Pair<Int, Int>, Int>()
    for (i in 0 until n) {
        val p = Pair(uf1.findRoot(i), uf2.findRoot(i))
        map[p] = (map[p] ?: 0) + 1
    }

    val ansList = IntArray(n)
    for (i in 0 until n) {
        val p = Pair(uf1.findRoot(i), uf2.findRoot(i))
        ansList[i] = map[p]!!
    }
    println(ansList.joinToString(" "))
}

/**　Union find 0 ~ (n - 1)　*/
class UnionFind(n: Int) {
    val parent = IntArray(n) { it }
    val rank = IntArray(n)
    val size = IntArray(n) { 1 }

    /** O(α(n)) */
    fun findRoot(x: Int): Int {
        if (parent[x] == x) return x

        parent[x] = findRoot(parent[x])
        return parent[x]
    }

    /** O(α(n)) */
    fun sameRoot(x: Int, y: Int) = findRoot(x) == findRoot(y)

    /** O(α(n)) */
    fun unite(x: Int, y: Int) {
        val x = findRoot(x)
        val y = findRoot(y)
        if (x == y) return

        if (rank[x] < rank[y]) {
            parent[x] = y
            size[y] += size[x]
        } else {
            parent[y] = x
            if (rank[x] == rank[y]) rank[x]++

            size[x] += size[y]
        }
    }

    /** O(α(n)) */
    fun getSize(x: Int) = size[findRoot(x)]
}

fun readInteger() = readLine()!!.toInt()
fun readLong() = readLine()!!.toLong()
fun readStringList() = readLine()!!.split(" ")
fun readIntegerList() = readStringList().map(String::toInt)
fun readLongList() = readStringList().map(String::toLong)
fun readDoubleList() = readStringList().map(String::toDouble)
