/**
 * Tree - Binary Trees
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

public class Main {

	static final int NIL = -1;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		//String line;

		int n = parseInt(br.readLine());
		Node[] T = new Node[n];

		StringTokenizer st;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			int id = parseInt(st.nextToken());
			T[id] = new Node();
			T[id].node = id;
			T[id].left = parseInt(st.nextToken());
			T[id].right = parseInt(st.nextToken());
		}
		// set parent
		for (int i = 0; i < n; i++) {
			if (T[i].left != NIL) T[T[i].left].parent = i;
			if (T[i].right != NIL) T[T[i].right].parent = i;
		}
		// set depth
		int root = 0;
		while (T[root].parent != NIL) root++;
		Deque<Node> stack;

		stack = new ArrayDeque<Node>();
		stack.push(T[root]);
		while (!stack.isEmpty()) {
			Node u = stack.pop();
			if (u.left != NIL) {
				T[u.left].depth = u.depth + 1;
				stack.push(T[u.left]);
			}
			if (u.right != NIL) {
				T[u.right].depth = u.depth + 1;
				stack.push(T[u.right]);
			}
		}
		// set height
		stack = new ArrayDeque<Node>();
		stack.push(T[root]);
		while (!stack.isEmpty()) {
			Node u = stack.pop();
			if (u.height == -1) {
				u.height = 0;
				stack.push(u);
				if (u.left != NIL) stack.push(T[u.left]);
				if (u.right != NIL) stack.push(T[u.right]);
			} else {
				u.height = Math.max(
						u.left != NIL ? T[u.left].height + 1 : 0,
						u.right != NIL ? T[u.right].height + 1 : 0
				);
			}
		}
		// set sibling
		for (int i = 0; i < n; i++) {
			if (T[i].left != NIL && T[i].right != NIL) {
				T[T[i].left].sibling = T[i].right;
				T[T[i].right].sibling = T[i].left;
			}
		}
		// set degree
		for (int i = 0; i < n; i++) {
			if (T[i].left != NIL) T[i].degree++;
			if (T[i].right != NIL) T[i].degree++;
		}
		// set type
		for (int i = 0; i < n; i++) {
			if (T[i].parent == NIL) {
				T[i].type = "root";
			} else if (T[i].left != NIL || T[i].right != NIL) {
				T[i].type = "internal node";
			} else {
				T[i].type = "leaf";
			}
		}
		// print
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(T[i].toString());
		}
		System.out.print(sb.toString());
	} //end main
}

class Node {
	int node;
	int parent = -1;
	int left = -1;
	int right = -1;
	//
	int degree = 0;
	int sibling = -1;
	int depth = 0;
	int height = -1;
	String type;

	public String toString() {
		return String.format(
				"node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",
				node,
				parent,
				sibling,
				degree,
				depth,
				height,
				type);
	}
}
