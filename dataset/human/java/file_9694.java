import java.util.Scanner;

class Node {
	int id, left, right;
	int parent = -1;
	int sibling = -1;	// ???????????°
	int degree;			// ????????°
	int depth;
	int height;

	public Node(int id) {
		this.id = id;
	}

	@Override
	public String toString() {

		String type;
		if(this.parent == -1) {
			type = "root";
		} else if (this.degree == 0) {
			type = "leaf";
		} else {
			type = "internal node";
		}

		String str =
				String.format(
						"node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s",
						this.id, this.parent, this.sibling, this.degree, this.depth, this.height, type);
		return str;
	}
}

class Main {

	static int treeDepth = 0;

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		Node[] bTree = new Node[n];

		for (int i = 0; i < n; i++) {
			bTree[i] = new Node(i);
		}

		for (int i = 0; i < n; i++) {
			int now = sc.nextInt();
			int left = sc.nextInt();
			int right = sc.nextInt();

			bTree[now].left = left;
			bTree[now].right = right;

			int deg = 0;
			if (left != -1) {
				deg++;
				bTree[left].parent = now;
			}
			if (right != -1) {
				deg++;
				bTree[right].parent = now;
			}
			if (left != -1 && right != -1) {
				bTree[left].sibling = right;
				bTree[right].sibling = left;
			}

			bTree[now].degree = deg;

		}
		sc.close();

		int root = -1;
		for(Node node : bTree) {
			if (node.parent == -1) {
				root = node.id;
				break;
			}
		}

		bTree[root].depth = 0;
		setDepth(root, bTree);
		setHeight(root, bTree);

		for (Node node : bTree) {
			System.out.println(node);
		}

	}

	private static void setHeight(int id, Node[] bTree) {
		int h1 = 0;
		int h2 = 0;

		Node now = bTree[id];

		if (now.left != -1) {
			setHeight(now.left, bTree);
			h1 = bTree[now.left].height + 1;
		}
		if (now.right != -1) {
			setHeight(now.right, bTree);
			h2 = bTree[now.right].height + 1;
		}

		now.height = Math.max(h1, h2);
	}

	private static void setDepth(int id, Node[] bTree) {
		Node now = bTree[id];

		if (now.left != -1) {
			bTree[now.left].depth = now.depth + 1;
			setDepth(now.left, bTree);
		}
		if (now.right != -1) {
			bTree[now.right].depth = now.depth + 1;
			setDepth(now.right, bTree);
		}

		treeDepth = Math.max(treeDepth, now.depth);
	}
}
