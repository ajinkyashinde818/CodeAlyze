import java.io.*
import java.util.*

fun solve(N: Int, A: IntArray, B: IntArray, C: IntArray){
    var ans = B[A[0] - 1]
    for (i in 1 until N){
        ans += B[A[i] - 1]
        if(A[i] == A[i-1] + 1) ans += C[A[i-1]-1]
    }
    println(ans)
    return
}


fun main(args: Array<String>) {
    fun StringArray(size: Int, init: (Int) -> String = { "\u0000" }): Array<String> {
        return Array<String>(size, init)
    }
    class Scanner(stream: InputStream) {
        private val reader = BufferedInputStream(stream).bufferedReader()
        private var st: StringTokenizer? = null
        fun next(): String {
            while (!(st?.hasMoreTokens() ?: false)) st = StringTokenizer(reader.readLine())
            return st!!.nextToken()
        }
    }
    val sc = Scanner(System.`in`)
    val N = sc.next().toInt()
    val A = IntArray(N)
    for (i in 0 until N) {
        A[i] = sc.next().toInt()
    }
    val B = IntArray(N)
    for (i in 0 until N) {
        B[i] = sc.next().toInt()
    }
    val C = IntArray((N-1))
    for (i in 0 until (N-1)) {
        C[i] = sc.next().toInt()
    }
    solve(N, A, B, C)
}
