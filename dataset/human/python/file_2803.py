import kotlin.math.sqrt

fun main(){
    var n = readLine()!!.split(" ")[0].toLong()
    val sqrt = sqrt(n.toDouble()).toLong()
    val soinsuu = mutableListOf<Long>()
    val kaisuu = mutableListOf<Int>()
    for (i in 2 until sqrt + 1){
        var count = 0
        if (n % i == 0L) {
            while (n % i == 0L) {
                count++
                n /= i
            }
            soinsuu += i
            kaisuu += count
        }
    }
    if (n > sqrt) {
        soinsuu += n
        kaisuu += 1
    }
    var ans = 0
    for (i in 0 until kaisuu.size){
        var j = 1
        while (kaisuu[i] >= 0){
            kaisuu[i] -= j
            j++
            ans++
            if (kaisuu[i] < j) break
        }
    }
    if (soinsuu.size == 0 && n != 1L){
        ans = 1
    }
    println(ans)
}
