import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {

		Scanner scan = new Scanner(System.in);
		// Scanner scan = new Scanner(new
		// File("D:\\UserArea\\J0124567\\Downloads\\ALDS1_6_A-in9.txt"));

		int n = scan.nextInt();
		Tree t = new Tree(n);

		for (int i = 0; i < n; i++) {
			int id = scan.nextInt();
			t.setLeftChild(id, scan.nextInt());
			t.setRightChild(id, scan.nextInt());
		}

		for (int i = 0; i < n; i++)
			t.printR(i);

		scan.close();
		System.exit(0);
	}
}

class Tree {
	private class Node {
		int Parent = -1;
		int LeftChild = -1;
		int RightChild = -1;

		public int getDepth() {
			if (Parent == -1)
				return 0;
			else
				return (node[Parent].getDepth() + 1);
		}

		public String getType() {
			if (Parent == -1)
				return "root";
			else if (LeftChild == -1 && RightChild == -1)
				return "leaf";
			else
				return "internal node";
		}

		public int getSib(int id) {
			if (Parent == -1)
				return -1;
			else if (node[Parent].LeftChild == id)
				return (node[Parent].RightChild);
			else
				return (node[Parent].LeftChild);
		}

		public int getDegree() {
			int r = 2;
			if (LeftChild == -1)
				r--;
			if (RightChild == -1)
				r--;
			return r;
		}

		public int getHeight() {
			if (getDegree() == 0)
				return 0;
			int l = 0, r = 0;
			if (LeftChild != -1)
				l = node[LeftChild].getHeight();
			if (RightChild != -1)
				r = node[RightChild].getHeight();
			return Math.max(l, r) + 1;
		}
	}

	private Node[] node;

	public Tree(int n) {
		node = new Node[n];
		for (int i = 0; i < n; i++) {
			node[i] = new Node();
		}
	}

	public void setRightChild(int id, int c) {
		node[id].RightChild = c;
		if (c != -1)
			node[c].Parent = id;
	}

	public void setLeftChild(int id, int c) {
		node[id].LeftChild = c;
		if (c != -1)
			node[c].Parent = id;
	}

	public void printR(int id) {
		System.out.println("node " + id + ": parent = " + node[id].Parent + ", sibling = " + node[id].getSib(id)
				+ ", degree = " + node[id].getDegree() + ", depth = " + node[id].getDepth() + ", height = "
				+ node[id].getHeight() + ", " + node[id].getType());
	}
}
