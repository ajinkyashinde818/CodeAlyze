import java.util.*

fun main(args: Array<String>) {
    val N = readLine()!!.toInt()
    val S = readLine()!!

    val v = S.map { if (it == 'B') 1L else 0L }
    val MOD = 1000000007L

    var c = 0L
    var res = ModInt(1, MOD)

    for (i in v.indices) {
        if (c % 2L == v[i]) {
            if (c == 0L) {
                println(0)
                return
            }

            res *= c
            c--
        } else {
            c++
        }
    }

    if (c != 0L) {
        println(0)
        return
    }

    for (i in 1L .. N) {
        res *= i
    }

    println(res.value)
}

class ModInt (value: Long, val mod: Long) {
    init {
        if (mod <= 0) {
            throw IllegalArgumentException("ModInt cannot be created for non-positive modulus: $mod")
        }
    }

    val value = (value % mod + mod) % mod

    private fun assertSameMod(other: ModInt) {
        if (mod != other.mod) {
            throw IllegalArgumentException(
                "You cannot operate summation, subtraction and multiplication for ModInts with different moduli: $mod, ${other.mod}"
            )
        }
    }

    operator fun unaryMinus() = ModInt(mod - value, mod)

    operator fun plus(other: ModInt): ModInt {
        assertSameMod(other)

        return ModInt((value + other.value) % mod, mod)
    }

    operator fun plus(other: Long) = plus(ModInt(other, mod))

    operator fun minus(other: ModInt): ModInt {
        assertSameMod(other)

        return plus(-other)
    }

    operator fun minus(other: Long) = minus(ModInt(other, mod))

    operator fun times(other: ModInt): ModInt {
        assertSameMod(other)

        return ModInt((value * other.value) % mod, mod)
    }

    operator fun times(other: Long) = times(ModInt(other, mod))

    fun pow(k: Long): ModInt {
        var res = 1L
        var a = value
        var l = k

        while (l > 0) {
            if ((l and 1L) == 1L) {
                res = (res * a) % mod
            }

            a = a * a % mod
            l /= 2L
        }

        return ModInt(res, mod)
    }

    /**
     * Returns an inverse element of the value.
     * To ensure `m * m.inv() = 1`, the modulus should be prime, since it uses Fermat's little theorem.
     */
    fun inv() = pow(mod - 2)

    operator fun div(other: ModInt): ModInt {
        assertSameMod(other)
        if (other.value == 0L) {
            throw ArithmeticException()
        }

        return times(other.inv())
    }

    operator fun div(other: Long) = div(ModInt(other, mod))
}
