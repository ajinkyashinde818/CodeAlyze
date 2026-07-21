import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
val sc = Scanner(System.`in`)

class Node(var par:Int, var lef: Int,var rig:Int) {
    fun show(){
        println("par: ${this.par}, lef: ${this.lef}, rig: ${this.rig}")
    }
}

fun main(args: Array<String>) {
    val n = nextInt()
    val fig = Array(n){Node(-1, -1, -1)}
    for(i in 0 until n){
        val (id, lef, rig) = nextListOfInt()
        fig[id].lef = lef
        fig[id].rig = rig
        if(lef != -1) fig[lef].par = id
        if(rig != -1) fig[rig].par = id
    }

    var root = -1
    for(i in 0 until n) {
        if (fig[i].par == -1) root = i
    }

    val H = Array(n){-1}
    val D = Array(n){-1}

    setHigh(fig, H, root)
    setDep(fig, D, root, 0)


    for(i in 0 until n){
        println("node $i: parent = ${fig[i].par}, sibling = ${getSib(fig, i, root)}, degree = ${getDeg(fig, i, root).first}," +
                " depth = ${D[i]}, height = ${H[i]}, ${getDeg(fig, i, root).second}")
    }
}

fun setHigh(fig: Array<Node>, H :Array<Int>, u :Int) : Int {
    var h1 = 0
    var h2 =0
    if(fig[u].rig != -1) h1 = setHigh(fig, H, fig[u].rig) + 1
    if(fig[u].lef != -1) h2 = setHigh(fig, H, fig[u].lef) + 1
    H[u] = Math.max(h1, h2)
    return Math.max(h1, h2)
}

fun setDep(fig: Array<Node>, D :Array<Int>, u :Int, d :Int) {
   if(u == -1) return
    D[u] = d
    setDep(fig, D, fig[u].rig, d+1)
    setDep(fig, D, fig[u].lef, d+1)
}

fun getSib(fig :Array<Node>, u :Int, root :Int) : Int{
    if(u == root) return -1
    if(fig[fig[u].par].rig != -1 && fig[fig[u].par].rig != u) return fig[fig[u].par].rig
    if(fig[fig[u].par].lef != -1 && fig[fig[u].par].lef != u) return fig[fig[u].par].lef
    return -1
}

fun getDeg(fig: Array<Node>, u: Int, root: Int) : Pair<Int, String> {
    var deg = 0
    var type: String
    if(fig[u].rig != -1) deg++
    if(fig[u].lef != -1) deg++
    type = if(deg == 0) "leaf" else "internal node"
    if(u == root) type = "root"
    return Pair(deg, type)
}


fun abc000a() {
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun nextListOfString() = next().split(" ")
fun nextListOfInt() = nextListOfString().map { it.toInt() }
fun nextListOfLong() = nextListOfString().map { it.toLong() }
fun nextListOfDouble() = nextListOfString().map { it.toDouble() }
