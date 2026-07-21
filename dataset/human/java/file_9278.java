import java.util.*

fun main(args: Array<String>) {
    val pw = java.io.PrintWriter(System.out)
    Problem.solve(Scanner(System.`in`), pw)
    pw.flush()
}

data class ModInt(var value: Long) {
    init {
        assert(value in 0 until MOD)
    }

    override fun toString(): String = value.toString()

    // 加減乗算は結果を毎回 mod P すれば良い
    operator fun plus(b: Long): ModInt =
        ModInt((this.value + b) % MOD)

    operator fun plus(b: Int): ModInt =
        ModInt((this.value + b) % MOD)

    operator fun plus(b: ModInt): ModInt =
        ModInt((this.value + b.value) % MOD)

    operator fun plusAssign(b: Long) {
        this.value += b
        this.value %= MOD
    }

    operator fun plusAssign(b: Int) {
        this.value += b
        this.value %= MOD
    }

    operator fun plusAssign(b: ModInt) {
        this.value += b.value
        this.value %= MOD
    }

    operator fun minus(b: Long): ModInt =
        ModInt((this.value + MOD - b) % MOD)

    operator fun minus(b: Int): ModInt =
        ModInt((this.value + MOD - b) % MOD)

    operator fun minus(b: ModInt): ModInt =
        ModInt((this.value + (MOD - b.value)) % MOD)

    operator fun minusAssign(b: Long) {
        this.value += MOD - b
        this.value %= MOD
    }

    operator fun minusAssign(b: Int) {
        this.value += MOD - b
        this.value %= MOD
    }

    operator fun minusAssign(b: ModInt) {
        this.value += MOD - b.value
        this.value %= MOD
    }

    operator fun times(b: Long): ModInt =
        ModInt((this.value * b) % MOD)

    operator fun times(b: Int): ModInt =
        ModInt((this.value * b) % MOD)

    operator fun times(b: ModInt): ModInt =
        ModInt((this.value * b.value) % MOD)

    operator fun timesAssign(b: Long) {
        this.value *= b
        this.value %= MOD
    }

    operator fun timesAssign(b: Int) {
        this.value *= b
        this.value %= MOD
    }

    operator fun timesAssign(b: ModInt) {
        this.value *= b.value
        this.value %= MOD
    }

    // b で割る = 1/b を掛ける
    // フェルマーの小定理から、b の逆数 1/b (mod P) = b^(P-2)
    operator fun div(b: Long): ModInt =
        this * ModInt(b).pow(MOD - 2)

    operator fun div(b: Int): ModInt =
        this * ModInt(b.toLong()).pow(MOD - 2)

    operator fun div(b: ModInt): ModInt =
        this * b.pow(MOD - 2)

    operator fun divAssign(b: Long) {
        this *= ModInt(b).pow(MOD - 2)
    }

    operator fun divAssign(b: Int) {
        this *= ModInt(b.toLong()).pow(MOD - 2)
    }

    operator fun divAssign(b: ModInt) {
        this *= b.pow(MOD - 2)
    }

    fun inv() = pow(MOD - 2)

    // 累乗 (mod P)
    // 計算量は O(log p)
    fun pow(p: Long): ModInt = when {
        p == 0L -> ModInt(1)
        p % 2 == 1L -> this * this.pow(p - 1)
        else -> {
            val half = this.pow(p / 2)
            half * half
        }
    }

    companion object {
        const val MOD = 1000000007L
    }
}

/*
 * aCb (mod P)
 *
 * 計算量は O(logN + N)
 *
 * https://www.youtube.com/watch?v=8uowVvQ_-Mo?t=1619 : ABC133
 */
class Combination(n: Int) {
    private val fact = arrayOfNulls<ModInt>(n + 1)
    private val ifact = arrayOfNulls<ModInt>(n + 1)

    init {
        fact[0] = ModInt(1L)
        for (i in 1..n) {
            fact[i] = fact[i - 1]!! * i
        }
        ifact[n] = fact[n]!!.inv()
        for (i in n downTo 1) {
            ifact[i - 1] = ifact[i]!! * i
        }
    }

    fun combination(n: Int, k: Int): ModInt =
        if (k in 0..n) fact[n]!! * ifact[k]!! * ifact[n - k]!! else ModInt(0L)
}

object Problem {
    fun solve(sc: Scanner, pw: java.io.PrintWriter) {
        val N = sc.next().toInt()
        val M = sc.next().toInt()
        val A = mutableListOf<Int>()
        var i = 0
        repeat(M) {
            val a = sc.next().toInt()
            A.add(a - 1 - i)
            i = a + 1
        }
        A.add(N - i)
        //dprint(A)

        if (A.contains(-1)) {
            pw.println("0")
            return
        }

        val ans = ModInt(1L)
        A.forEach { n ->
            val c = Combination(n)
            val a = ModInt(0L)
            if (n > 0) {
                for (k in 0..n / 2) {
                    a += c.combination(n - k, k)
                }
                //dprint("n=$n : $a")
                ans *= a
            }
        }
        pw.println(ans)
    }
}
