import java.util.*

class Node {
    var left = -1
    var right = -1
    var parent = -1
    var depth = -1
    var degree = 0
    var height = -1
}

class BinaryTree(var n: Int) {
    var nodes = Array(n) { Node() }

    fun setNode(id: Int, left: Int, right: Int) {
        nodes[id].left = left
        nodes[id].right = right
        if (left != -1) { nodes[left].parent = id; nodes[id].degree += 1 }
        if (right != -1) { nodes[right].parent = id; nodes[id].degree += 1 }
    }

    fun getDepth(id: Int) : Int {
        if (nodes[id].depth != -1) return nodes[id].depth
        nodes[id].depth = when (nodes[id].parent) {
            -1 -> 0
            else -> getDepth(nodes[id].parent) + 1
        }
        return nodes[id].depth
    }

    fun getSibling(id: Int) : Int {
        if (nodes[id].parent != -1) {
            val parent = nodes[nodes[id].parent]
            return if (parent.left == id) parent.right else parent.left
        }
        return -1
    }

    fun getHeight(id: Int) : Int {
        if (id == -1) return -1
        if (nodes[id].height == -1) {
            nodes[id].height = Math.max(getHeight(nodes[id].left), getHeight(nodes[id].right)) + 1
        }
        return nodes[id].height
    }

    fun hoge() {
        for (i in 0 until n) {
            val node = nodes[i]
            println("node ${i}: parent = ${node.parent}, sibling = ${getSibling(i)}, degree = ${node.degree}, depth = ${getDepth(i)}, height = ${getHeight(i)}, ${if (node.parent == -1) "root" else if (node.height == 0) "leaf" else "internal node"}")
        }
    }
}

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    val tree = BinaryTree(n)
    for (i in 1..n) {
        val a = Array<Int>(3) { sc.nextInt() }
        tree.setNode(a[0], a[1], a[2])
    }
    tree.hoge()
}
