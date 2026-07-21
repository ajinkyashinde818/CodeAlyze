import kotlin.String

fun main(args: Array<String>) {
    val n = readLong()

    if (n % 2 != 0L) {
        println(0)
        return
    }

    var ans = 0L
    var t = 10L
    while (t <= n) {
        ans += n / t
        t *= 5
    }
    println(ans)
}

// read
fun readString() = readLine()!!
fun readInt() = readLine()!!.toInt()
fun readLong() = readLine()!!.toLong()
fun readStringList() = readLine()!!.split(" ")
fun readIntList() = readLine()!!.split(" ").map(String::toInt)
fun readLongList() = readLine()!!.split(" ").map(String::toLong)
