import java.io.BufferedReader
import java.io.IOException
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*


fun main(args: Array<String>) {
    val inputReader = InputReaderc(System.`in`)

    val s = inputReader.nextLine().split(" ").map { i -> i.toLong() }

    print(lcm(s[0], s[1]))
}

fun lcm(i: Long, j: Long): Long {
    return (i * j) / gcd(i, j)
}

fun gcd(i: Long, j: Long): Long {
    return if (i == 0L) j else gcd(j % i, i)
}

class InputReaderc(stream: InputStream) {
    private var reader: BufferedReader = BufferedReader(InputStreamReader(stream))
    private var tokenizer: StringTokenizer? = null

    init {
        tokenizer = null
    }

    operator fun next(): String {
        while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
            try {
                tokenizer = StringTokenizer(reader.readLine())
            } catch (e: IOException) {
                throw RuntimeException(e)
            }

        }
        return tokenizer!!.nextToken()
    }

    fun nextInt(): Int {
        return Integer.parseInt(next())
    }

    fun nextLong(): Long {
        return java.lang.Long.parseLong(next())
    }

    fun nextDouble(): Double {
        return java.lang.Double.parseDouble(next())
    }

    fun nextLine(): String {
        var str = ""
        try {
            str = reader.readLine()
        } catch (e: IOException) {
            e.printStackTrace()
        }

        return str
    }
}
