import java.util.*

private fun getInts() : List<Int> {
    return readLine()!!.split(" ").map {it.toInt()}
}

class Node {
    val connected : MutableSet<Node> = HashSet()

    fun connectTo(another: Node) {
        this.connected.add(another)
        another.connected.add(this)
    }
}

fun main(args: Array<String>) {
    val fl = getInts()
    val N = fl[0]
    val M = fl[1]

    val nodes = ArrayList<Node>()
    (1..N).forEach {
        nodes.add(Node())
    }
    (1..M).forEach {
        val ab = getInts()
        val a = ab[0]
        val b = ab[1]
        nodes[a - 1].connectTo(nodes[b - 1])
    }

    if (nodes[0].connected.find { it.connected.contains(nodes[N - 1]) } == null) {
        println("IMPOSSIBLE")
    } else {
        println("POSSIBLE")
    }
}
