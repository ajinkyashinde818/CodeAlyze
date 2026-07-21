import kotlin.math.abs

fun main() {
    val s = readLine() ?: return
    fun String.isPalindrome() = take(length / 2) == takeLast(length / 2).reversed()
    val withoutX = s.replace("x", "")
    if (!withoutX.isPalindrome()) {
        println("-1")
        return
    }
    var i = 0
    var index = 0
    val half = withoutX.length / 2 + withoutX.length % 2
    val counter = Array(half) { 0 }
    while (half > i) {
        when (s[index]) {
            'x' -> counter[i]++
            else -> {
                i++
            }
        }
        index++
    }
    i = 0
    index = 0
    var count = 0
    while (half > i) {
        when (s[s.length - index - 1]) {
            'x' -> counter[i]--
            else -> {
                count += abs(counter[i])
                i++
            }
        }
        index++
    }
    println(count.toString())
}
