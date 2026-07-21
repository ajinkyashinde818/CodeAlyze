import java.io.*
import java.util.*

const val YES = "Yes"
const val NO = "No"
fun solve(s: String, t: String){
    val s_ = s.toList().sorted().joinToString(separator = "")
    val t_ = t.toList().sortedDescending().joinToString(separator = "")
    if (s_ < t_) println(YES)
    else println(NO)
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
    val s = sc.next()
    val t = sc.next()
    solve(s, t)
}
