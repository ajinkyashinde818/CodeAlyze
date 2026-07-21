import java.util.*;

class Node {
	public int id, degree, depth, height;
	public Node parent, sibling, left, right;
	Node(int id) {
		this.id = id;
		this.degree = 0;
		this.depth = 0;
		this.height = 0;
	}
	void setLeft(Node node) {
		left = node;
		left.parent = this;
		degree++;
	}
	void setRight(Node node) {
		right = node;
		right.parent = this;
		degree++;
	}
	void setSibling() {
		if (left != null && right != null) {
			left.sibling = right;
			right.sibling = left;
		}
	}
	void setDepth(int depth) {
		this.depth = depth;
		if (left != null) left.setDepth(depth + 1);
		if (right != null) right.setDepth(depth + 1);
	}
	void setHeight(int height) {
		if (height >= this.height) {
			this.height = height;
		}
		if (parent != null) parent.setHeight(this.height + 1);
	}
}

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		Node[] tree = new Node[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new Node(i);
		}
		for (int i = 0; i < n; i++) {
			Node node = tree[scanner.nextInt()];
			int left = scanner.nextInt();
			if (left != -1) node.setLeft(tree[left]);
			int right = scanner.nextInt();
			if (right != -1) node.setRight(tree[right]);
			node.setSibling();
		}
		Node root = null;
		for (int i = 0; i < n; i++) {
			if (tree[i].parent == null) {	
				root = tree[i];
				break;
			}
		}
		root.setDepth(0);
		for (int i = 0; i < n; i++) {
			tree[i].setHeight(0);
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append("node ");
			sb.append(tree[i].id);
			sb.append(": parent = ");
			sb.append(tree[i].parent == null ? -1 : tree[i].parent.id);
			sb.append(", sibling = ");
			sb.append(tree[i].sibling == null ? -1 : tree[i].sibling.id);
			sb.append(", degree = ");
			sb.append(tree[i].degree);
			sb.append(", depth = ");
			sb.append(tree[i].depth);
			sb.append(", height = ");
			sb.append(tree[i].height);
			sb.append(", ");
			if (tree[i].parent == null) {
				sb.append("root");
			} else {
				if (tree[i].left == null && tree[i].right == null) {
					sb.append("leaf");
				} else {
					sb.append("internal node");
				}
			}
			sb.append("\n");
		}
		System.out.print(sb);
	}
}
