import kotlin.String

fun main(args: Array<String>) {
    val n = readInt()
    val s = readString()

    val cnt = MutableList(26) { 0 }
    s.forEach {
        cnt[it - 'a']++
    }
    var ans = 1L
    cnt.forEach {
        if (it > 0) {
            ans = (ans * (it + 1L) % 1000000007L) % 1000000007L
        }
    }
    println(ans - 1)
}

// Tools
fun readString() = readLine()!!
fun readInt() = readLine()!!.toInt()
