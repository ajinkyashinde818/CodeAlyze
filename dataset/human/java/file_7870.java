import kotlin.math.*
import java.util.*

data class Visit(var seq: Int = 0, var visited: Boolean = false)

fun main(args: Array<String>) {
  val (_n, _k) = readLine()!!.split(' ')
  val n = _n.toInt()
  val k = _k.toLong()
  val a = readLine()!!.split(' ').map(String::toInt)

  val v = Array(n) { Visit() }
  val r = mutableListOf<Int>()
  var cur = 1
  var seq = 0
  while (!v[cur - 1].visited) {
    val visit = v[cur - 1]
    visit.seq = seq++
    visit.visited = true
    r += cur
    cur = a[cur - 1]
  }
  val p = v[cur - 1]
  val len = r.size - p.seq
  if (k <= p.seq) {
    println(r[k.toInt()])
  } else {
    println(r[p.seq + ((k - p.seq) % len).toInt()])
  }
}
