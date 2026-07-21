import java.util.Scanner;

public class Main {

	private static Node2[] nodes;

	private static int[] degree;

	public static void main(String[] args) {
		// TODO ?????????????????????????????????????????????
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();

		nodes = new Node2[n];

		degree = new int[n];

		int[] depth = new int[n];

		int[] height = new int[n];

		String[] type = new String[n];

		for (int i = 0; i < n; i++) {
			nodes[i] = new Node2(-1, -1, -1, -1);
		}

		for (int i = 0; i < n; i++) {
			int node = sc.nextInt();
			int left = sc.nextInt();
			int right = sc.nextInt();

			if (left == -1) {
				if (right == -1) {
					degree[node] = 0;
				} else {
					nodes[right].parent = node;
					nodes[node].right = right;
					degree[node] = 1;
				}
			} else {
				if (right == -1) {
					nodes[left].parent = node;
					nodes[node].left = left;
					degree[node] = 1;
				} else {
					nodes[right].parent = node;
					nodes[left].parent = node;
					nodes[right].sibling = left;
					nodes[left].sibling = right;
					nodes[node].right = right;
					nodes[node].left = left;
					degree[node] = 2;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			if (nodes[i].parent == -1) {
				type[i] = "root";
			} else if (degree[i] == 0) {
				type[i] = "leaf";
			} else {
				type[i] = "internal node";
			}
		}

		for (int i = 0; i < n; i++) {
			depth[i] = setDepth(i);
		}

		for (int i = 0; i < n; i++) {
			height[i] = setHeight(i);
		}

		for (int i = 0; i < n; i++) {
			StringBuilder kari = new StringBuilder();
			kari.append("node ");
			kari.append(i);
			kari.append(": parent = ");
			kari.append(nodes[i].parent);
			kari.append(", sibling = ");
			kari.append(nodes[i].sibling);
			kari.append(", degree = ");
			kari.append(degree[i]);
			kari.append(", depth = ");
			kari.append(depth[i]);
			kari.append(", height = ");
			kari.append(height[i]);
			kari.append(", ");
			kari.append(type[i]);
			System.out.println(kari);

		}
	}

	public static int setDepth(int u) {
		if (nodes[u].parent == -1) {
			return 0;
		} else {
			return setDepth(nodes[u].parent) + 1;
		}
	}

	public static int setHeight(int u) {
		if (degree[u] == 0) {
			return 0;
		} else if (nodes[u].left == -1) {
			return setHeight(nodes[u].right) + 1;
		} else if (nodes[u].right == -1) {
			return setHeight(nodes[u].left) + 1;
		} else {
			return Math
					.max(setHeight(nodes[u].left), setHeight(nodes[u].right)) + 1;
		}
	}
}

class Node2 {
	int parent;
	int sibling;
	int left;
	int right;

	public Node2(int parent, int sibling, int left, int right) {
		super();
		this.parent = parent;
		this.sibling = sibling;
		this.left = left;
		this.right = right;
	}

}
