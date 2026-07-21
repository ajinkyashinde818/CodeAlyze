import kotlin.math.min

fun readString() = readLine()!!
fun readInt() = readLine()!!.toInt()
fun readLong() = readLine()!!.toLong()
fun readIntList() = readLine()!!.split(" ").map(String::toInt)
fun readLongList() = readLine()!!.split(" ").map(String::toLong)
fun <T> Array<Array<T>>.print() {
    this.forEach {
        println(it.joinToString(" "))
    }
}

fun main() {
    val (k, _) = readIntList()
    val a = readIntList()
    var res = k
    a.forEachIndexed { i, _ ->
        val d = if (i == a.count() - 1) {
            k - (a[0] + (k - a.last()))
        } else {
            k - (a[i+1] - a[i])
        }
        res = min(res, d)
    }
    println(res)
}
