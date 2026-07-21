import java.util.Scanner;

class Node {
	int i, id, left, right, parent = -1, sibling = -1, degree = 0, depth = 0, height = 0;

	public Node(int Id, int l, int r) {
		id = Id;
		left = l;
		right = r;
	}

	public void Show() {

		System.out.print("node " + id + ": parent = " + parent + ", sibling = " + sibling + ", degree = " + degree
				+ ", depth = " + depth + ", height = " + height + ", ");
		if (parent == -1) {
			System.out.println("root");
		} else if (degree == 0) {
			System.out.println("leaf");
		} else {
			System.out.println("internal node");
		}
	}
}

public class Main {
	static Node[] node = new Node[100000];

	public static void hight(int i) {
		if (node[i].parent != -1 && node[node[i].parent].height < node[i].height + 1) {
			node[node[i].parent].height = node[i].height + 1;
			hight(node[i].parent);
		}
	}

	public static void depth(int i) {
		if (node[i].left != -1) {
			node[node[i].left].depth=node[i].depth+1;
			depth(node[i].left);
		}
		if (node[i].right != -1) {
			node[node[i].right].depth=node[i].depth+1;
			depth(node[i].right);
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int i, n, id, l, r;
		n = scan.nextInt();
		for (i = 0; i < n; i++) {
			id = scan.nextInt();
			l = scan.nextInt();
			r = scan.nextInt();
			node[id] = new Node(id, l, r);
		}
		for (i = 0; i < n; i++) {
			if (node[i].left != -1) {
				node[i].degree++;
				node[node[i].left].parent = node[i].id;
				node[node[i].left].sibling = node[i].right;
			}
			if (node[i].right != -1) {
				node[i].degree++;
				node[node[i].right].parent = node[i].id;
				node[node[i].right].sibling = node[i].left;
			}
		}
		for (i = 0; i < n; i++) {
			if (node[i].parent == -1) {
				depth(i);
			}
			if (node[i].degree == 0) {
				hight(i);
			}
		}
		for (i = 0; i < n; i++) {
			node[i].Show();
		}
		scan.close();
	}
}
