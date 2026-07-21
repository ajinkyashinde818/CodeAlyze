import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static Node[] nodes;
    public static void main (String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int n = Integer.parseInt(br.readLine());
	nodes = new Node[n];
	for (int i = 0; i < n; i++) {
	    nodes[i] = new Node(i);
	}
	String[] input;
	int id, left, right;
	for (int i = 0; i < n; i++) {
	    input = br.readLine().split(" ");
	    id = Integer.parseInt(input[0]);
	    left = Integer.parseInt(input[1]);
	    right = Integer.parseInt(input[2]);
	    nodes[id].id = id;
	    nodes[id].left = left;
	    nodes[id].right = right;
	    if (left == -1 && right == -1) {
		nodes[id].type = 1;
		nodes[id].height = 0;
	    }
	    if (left != -1) {
		nodes[left].parent = id;
		nodes[left].sibling = right;
		nodes[id].degree += 1;
	    }
	    if (right != -1) {
		nodes[right].parent = id;
		nodes[right].sibling = left;
		nodes[id].degree += 1;
	    }
	}
	for (int i = 0; i < n; i++) {
	    nodes[i].depth = setDepth(i);
	}
	
	for (int i = 0; i < n; i++) {
	    nodes[i].height = setHeight(i);
	}
	printNodes(nodes);
    }

    public static int setDepth (int id) {
	if (nodes[id].depth >= 0) {
	    return nodes[id].depth;
	}
	if (nodes[id].parent == -1) {
	    nodes[id].type = -1;
	    return nodes[id].depth = 0;
	}
	return nodes[id].depth = setDepth(nodes[id].parent) + 1;
    }

    public static int setHeight (int id) {
	if (id < 0) {
	    return Integer.MIN_VALUE;
	}
	if (nodes[id].height >= 0) {
	    return nodes[id].height;
	}
	return nodes[id].height = Math.max(setHeight(nodes[id].left), setHeight(nodes[id].right)) + 1;
    }
    
    static void printNodes (Node[] nodes) {
	int n = nodes.length;
	StringBuilder sb = new StringBuilder();
	for (int id = 0; id < n; id++) {
	    sb.append("node " + id);
	    sb.append(": parent = " + nodes[id].parent);
	    sb.append(", sibling = " + nodes[id].sibling);
	    sb.append(", degree = " + nodes[id].degree);
	    sb.append(", depth = " + nodes[id].depth);
	    sb.append(", height = " + nodes[id].height);
	    if (nodes[id].type == -1) {
		sb.append(", root\n");
	    } else if (nodes[id].type == 0) {
		sb.append(", internal node\n");
	    } else if (nodes[id].type == 1) {
		sb.append(", leaf\n");
	    }
	}
	System.out.print(sb);
    }
}
class Node {
    int id;
    int left;
    int right;
    int parent;
    int sibling;
    int degree;
    int depth;
    int height;
    int type; // -1: root, 0: internal node, 1: leaf
    Node (int id) {
	this.id = id;
	type = 0;
	degree = 0;
	sibling = -1;
	parent = -1;
	depth = -1;
	height = -1;
    }
}
