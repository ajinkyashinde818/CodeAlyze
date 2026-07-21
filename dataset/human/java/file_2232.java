import kotlin.math.*
import java.util.*

const val mod = 1000000007L

fun readI() = readLine()!!.toInt()
fun readL() = readLine()!!.toLong()
fun readD() = readLine()!!.toDouble()
fun readIs() = readLine()!!.split(' ').map(String::toInt)
fun readLs() = readLine()!!.split(' ').map(String::toLong)
fun readDs() = readLine()!!.split(' ').map(String::toDouble)

fun sqrt(x: Long) = sqrt(x.toDouble()).toLong()

data class Power(val base: Long, val exp: Int)

fun pfactor(n: Long): List<Power> {
  val factors = mutableListOf<Power>()
  var m = n
  var p = 2L
  var e = 0
  while (m % p == 0L) {
    m /= p
    e++
  }
  if (0 < e) factors += Power(p, e)
  p = 3
  var pmax = sqrt(m)
  while (m != 1L && p <= pmax) {
    e = 0
    while (m % p == 0L) {
      m /= p
      e++
    }
    if (0 < e) {
      factors += Power(p, e)
      pmax = sqrt(m)
    }
    p += 2
  }
  if (m != 1L) factors += Power(m, 1)
  return factors
}

fun main(args: Array<String>) {
  var n = readL()
  var ans = 0L
  for (pf in pfactor(n)) {
    var e = pf.exp
    var i = 0
    while (0 < e) {
      i++
      e -= i
    }
    ans += if (e < 0) i - 1 else i
  }
  println(ans)
}
