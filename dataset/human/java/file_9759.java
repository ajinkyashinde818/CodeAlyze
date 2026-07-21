import java.lang.Math.max

data class Node(var parentNodeNum: Int = -1, var sibling: Int = -1, var degree: Int = 0, var depth: Int = 0, var height: Int = 0,
                var nodeType: NodeType = NodeType.ROOT, var left: Pair<Int, Node>? = null, var right: Pair<Int, Node>? = null)
enum class NodeType {
    ROOT {
        override fun toString() = "root"
    },
    INTERNAL_NODE {
        override fun toString() = "internal node"
    },
    LEAF {
        override fun toString() = "leaf"
    }
}

fun main(args: Array<String>) {
    val inputList = List(readLine()?.toInt() ?: return) {
        readLine()?.split(" ".toRegex())?.map(String::toInt) ?: listOf()
    }
    val nodeMap = mutableMapOf<Int, Node>()
    inputList.forEach { input ->
        val nodeNum = input[0]
        nodeMap.putIfAbsent(nodeNum, Node())
        nodeMap[nodeNum]?.let { node ->
            if (input[1] != -1) {
                val leftNum = input[1]
                nodeMap.putIfAbsent(leftNum, Node())
                node.left = leftNum to nodeMap[leftNum]!!
                nodeMap[leftNum]?.parentNodeNum = nodeNum
                node.degree++
            }
            if (input[2] != -1) {
                val rightNum = input[2]
                nodeMap.putIfAbsent(rightNum, Node())
                node.right = rightNum to nodeMap[rightNum]!!
                nodeMap[rightNum]?.parentNodeNum = nodeNum
                node.degree++
            }
            node.left?.second?.sibling = node.right?.first ?: -1
            node.right?.second?.sibling = node.left?.first ?: -1
        }
    }
    recDepth(nodeMap.values.first { it.parentNodeNum == -1 }, 0)
    val stringBuilder = StringBuilder()
    for (i in inputList.indices) {
        nodeMap[i]?.let { node ->
            stringBuilder.append("node $i: parent = ${node.parentNodeNum}, sibling = ${node.sibling}, degree = ${node.degree}, depth = ${node.depth}, height = ${node.height}, ${node.nodeType}\n")
        }
    }
    print(stringBuilder.toString())
}

fun recDepth(node: Node, depth: Int): Int {
    node.depth = depth
    when {
        node.parentNodeNum == -1 -> node.nodeType = NodeType.ROOT
        node.right == null && node.left == null -> node.nodeType = NodeType.LEAF
        else -> node.nodeType = NodeType.INTERNAL_NODE
    }
    val leftHeight = if (node.left != null) {
        recDepth(node.left!!.second, depth + 1)
    } else {
        0
    }
    val rightHeight = if (node.right != null) {
        recDepth(node.right!!.second, depth + 1)
    } else {
        0
    }
    node.height = max(leftHeight, rightHeight)
    return node.height + 1
}
