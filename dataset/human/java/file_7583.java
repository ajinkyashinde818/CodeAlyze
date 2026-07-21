import java.io.InputStream
import java.io.PrintStream
import java.util.*

class Arc065A(
    val input: InputStream,
    val output: PrintStream
) {
    fun proc() {
        val sc = Scanner(input)
        var input = sc.nextLine()

        val strs = listOf("dream", "dreamer", "erase", "eraser")

        while (input.isNotEmpty()) {
            val a = strs.find { input.endsWith(it) }
            if (a == null) {
                output.print("NO")
                return
            }
            input = input.removeSuffix(a)
        }
        output.print("YES")
    }
}

fun main(args: Array<String>) {
    Arc065A(System.`in`, System.out).proc()
}
