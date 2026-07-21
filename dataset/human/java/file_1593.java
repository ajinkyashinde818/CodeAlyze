import java.util.Scanner

fun main(args: Array<String>) {
    data class Input(val n: Int, val m: Int, val a: List<String>, val b: List<String>)
    val (n, m, a, b) = Scanner(System.`in`).use<Scanner, Input> {
        val n = it.nextInt()    //1≦M≦N≦50
        val m = it.nextInt()
        val a: MutableList<String> = mutableListOf()
        repeat(n, {n -> a.add(it.next())})
        val b: MutableList<String> = mutableListOf()
        repeat(m, {m -> b.add(it.next())})

        Input(n, m, a, b)       // 返した後はイミュータブルリスト扱い
    }

    // m, n が少ないので、bitなどを使用せず、正規表現を用いる。
    val firstLine = Regex(b[0], RegexOption.LITERAL)
    val result = (0..n - m).any { i ->        // n-mで一致したらn-m+m-1 = n-1で終わる。
        // 1行目に一致がある行を探す
        val matchResults = firstLine.findAll(a[i])
        matchResults.any { matchResult ->      // 一致がなければ以下は無視されfalseが返る。
            val range = matchResult.range
            // i以下の行全てで一致するか確認する。
            (1 .. m - 1).all {           // m == 1の時はtrueが返るがそれでよい。
                b[it] == a[i + it].slice(range)
            }
        }
    }
    print(if (result) "Yes" else "No")
}
