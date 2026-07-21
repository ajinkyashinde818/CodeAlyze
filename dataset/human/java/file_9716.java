import java.util.Scanner;

class Node {

	int id, parent, left, right, sibling, degree, depth, height;
	String type;

	public Node(int id, int left, int right) {
		super();
		this.id = id;
		this.left = left;
		this.right = right;
		this.parent = -1;
	}

	@Override
	public String toString() {
		return "node " + id + ": parent = " + parent + ", sibling = " + sibling +
				", degree = " + degree + ", depth = " + depth + ", height = " + height +
				", " + type;
	}
}

public class Main {


	public static void nodeDownward(Node[] nodeList, int parent, int child, int sibling, int depth) {
		Node node = nodeList[child];
		node.parent = parent;
		node.depth = depth;
		node.sibling = sibling;
		node.depth = depth++;
		int left = node.left;
		int right = node.right;
//		System.out.println("node:" + node.id + " left:" + left + " right:" + right +
//				" parent:" + node.parent);
		if (left != -1) {
			nodeDownward(nodeList, node.id, left, right, depth);
		}
		if (right != -1) {
			nodeDownward(nodeList, node.id, right, left, depth);
		}
	}

	public static void leafToRoot(Node[] nodeList, int id, int height) {
		Node node = nodeList[id];
		node.height = Math.max(height++, node.height);
		if (node.parent == -1) {
			return;
		}
		leafToRoot(nodeList, node.parent, height);
	}


	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		Node[] node = new Node[n];
		int[] rootNode = new int[n];

		for (int i = 0; i < n; i++) {
			int id = sc.nextInt(), left = sc.nextInt(), right = sc.nextInt();
			node[id] = new Node(id, left, right);
			node[id].type = "internal node";

			if (left != -1) {
				rootNode[left] = 1;
				node[id].degree = 1;

			}
			if (right != -1) {
				rootNode[right] = 1;
				node[id].degree = 1;
			}
			if (left == -1 && right == -1) {
				node[id].type = "leaf";
			}

			if (left != -1 && right != -1) {
				node[id].degree = 2;

			}

		}
		int root = 0;
		for (int i = 0; i < n; i++) {
			if (rootNode[i] == 0) {
				root = i;
				node[i].type = "root";
			}
		}

		nodeDownward(node, -1, root, -1, 0);

		for (int i = 0; i < node.length; i++) {
			if (node[i].type.equals("leaf")) {
				leafToRoot(node, i, 0);
			}
		}

		for (int i = 0; i < n; i++) {
			System.out.println(node[i]);
		}
	}
}
