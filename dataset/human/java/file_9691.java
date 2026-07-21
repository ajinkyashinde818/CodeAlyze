import java.io.IOException;
import java.util.Scanner;
import java.lang.Math;

// ALDS1_7_B
public class Main {
	void searchDepth(Node[] tree, int i, int n) {
		tree[i].depth = n;
		if (tree[i].left != -1) searchDepth(tree, tree[i].left, n+1);
		if (tree[i].right != -1) searchDepth(tree, tree[i].right, n+1);
	}
	
	int searchHeight(Node[] tree, int i) {
		if (i == -1) return 0;
		tree[i].height = Math.max(searchHeight(tree, tree[i].left), searchHeight(tree, tree[i].right));
		return tree[i].height + 1;
	}
	
	void run() throws IOException {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Node[] tree = new Node[n];
		for (int i = 0; i < n; i++) {
			tree[i] = new Node(i);
		}
		for (int i = 0; i < n; i++) {
			int number = sc.nextInt();
			int left = sc.nextInt();
			int right = sc.nextInt();
			tree[number].left = left;
			tree[number].right = right;
			if (left != -1 && right != -1) {
				tree[number].degree = 2;
				tree[number].type = "internal node";
				tree[left].parent = number;
				tree[left].sibling = right;
				tree[right].parent = number;
				tree[right].sibling = left;
			} else if (left != -1 || right != -1) {
				tree[number].degree = 1;
				tree[number].type = "internal node";
				if (left != -1) tree[left].parent = number;
				if (right != -1) tree[right].parent = number;
			} else {
				tree[number].degree = 0;
				tree[number].type = "leaf";
			}
		}
		// search root
		int root = 0;
		for (int i = 0; i < tree.length; i++) {
			if (tree[i].parent == -1) {
				tree[i].type = "root";
				root = i;
			}
		}
		searchDepth(tree, root, 0);
		searchHeight(tree, root);
		for (int i = 0; i < n; i++) {
			tree[i].print();
		}
		sc.close();
	}
	
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
}

class Node {
	int number;
	int parent = -1;
	int sibling = -1;
	int degree;
	int left;
	int right;
	int depth;
	int height = 0;
	String type;
	Node(int number) {
		this.number = number;
	}
	
	void print() {
		System.out.println("node " + number + ": parent = " + parent + ", sibling = " + sibling + ", degree = " + degree + 
				", depth = " + depth + ", height = " + height + ", " + type);
	}
}
