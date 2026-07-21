import java.util.*;
import java.io.*;

public class Main {
	static class Node {
		int notNIL = 1;
		int id = -1;
		Node parent = NIL;
		Node left = NIL;
		Node right = NIL;
		Node sibling = NIL;
		int degree;
		int depth = -2;
		int height = -2;
	}
	static Node NIL = new Node();
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();
		Node[] tree = new Node[n + 1];
		NIL.notNIL = 0;
		NIL.depth = -1;
		NIL.height = -1;
		tree[0] = NIL;
		for (int i = 1; i < n + 1; i ++) {
			tree[i] = new Node();
		}

		for (int i = 0; i < n; i ++) {
			int id = scanner.nextInt();
			Node u = tree[id + 1];
			u.id = id;
			
			Node left = tree[scanner.nextInt() + 1];
			u.left = left;
			left.parent = u;
			
			Node right = tree[scanner.nextInt() + 1];
			u.right = right;
			right.parent = u;
			
			left.sibling = right;
			right.sibling = left;
			
			u.degree = left.notNIL + right.notNIL;
		}

		scanner.close();
		
		for (int i = 1; i < n + 1; i ++) {
			Node u = tree[i];
			System.out.print("node ");
			System.out.print(u.id);
			System.out.print(": parent = ");
			System.out.print(u.parent.id);
			System.out.print(", sibling = ");
			System.out.print(u.sibling.id);
			System.out.print(", degree = ");
			System.out.print(u.degree);
			System.out.print(", depth = ");
			System.out.print(getDepth(u));
			System.out.print(", height = ");
			System.out.print(getHeight(u));
			System.out.print(", ");
			System.out.println((u.parent == NIL) ? "root": ((u.degree != 0) ? "internal node": "leaf"));
		}
	}
	
	static int getDepth(Node u) {
		if (u.depth != -2) return u.depth;
		u.depth = getDepth(u.parent) + 1;
		return u.depth;
	}
	
	static int getHeight(Node u) {
		if (u.height != -2) return u.height;
		u.height = Math.max(getHeight(u.left), getHeight(u.right)) + 1;
		return u.height;
	}
}
