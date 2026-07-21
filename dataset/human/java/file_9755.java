import java.util.*;

class Node{
	int id;
	int parent, left, right, sibling, depth, height;

	public Node(int id){
		this.id = id;
		this.parent = -1;
		this.left = -1;
		this.right = -1;
		this.sibling = -1;
		this.depth = -1;
		this.height = -1;
	}
}

class Nodes{
	Node[] nodes;

	public void setDepth(int id, int d){
		int l = nodes[id].left;
		int r = nodes[id].right;
		if(l != -1)
			setDepth(l, d+1);
		if(r != -1)
			setDepth(r, d+1);
		nodes[id].depth = d;
	}

	public int setHeight(int id){
		if(id == -1)
			return -1;
		int l = nodes[id].left;
		int r = nodes[id].right;
		nodes[id].height = Math.max(setHeight(l), setHeight(r)) + 1;
		return nodes[id].height;
	}

	public void printNode(int id){
		StringBuffer sb = new StringBuffer();
		int degree = 0;
		if(nodes[id].left != -1) degree++;
		if(nodes[id].right != -1) degree++;
		sb.append("node " + id + ": parent = " + nodes[id].parent 
					+ ", sibling = " + nodes[id].sibling + ", degree = " + degree 
					+ ", depth = " + nodes[id].depth 
					+ ", height = " + nodes[id].height + ", ");
		if(nodes[id].parent == -1) sb.append("root\n");
		else if(degree == 0) sb.append("leaf\n");
		else sb.append("internal node\n");
		System.out.print(sb);
	}
}

public class Main{

	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();

		Nodes mynodes = new Nodes();
		Node[] nodes = new Node[n];
		mynodes.nodes = nodes;
		for(int i = 0; i < n; i++)
			nodes[i] = new Node(i);
		for(int i = 0; i < n; i++){
			int id = scan.nextInt();
			int left = scan.nextInt();
			int right = scan.nextInt();
			if(left != -1) nodes[left].parent = id;
			if(right != -1) nodes[right].parent = id;
			nodes[id].left = left;
			nodes[id].right = right;
			if(left != -1 && right != -1){
				nodes[left].sibling = right;
				nodes[right].sibling = left;
			}
		}
		int root = 0;
		while(nodes[root].parent != -1)
			root = nodes[root].parent;
		mynodes.setDepth(root, 0);
		nodes[root].height = mynodes.setHeight(root);
		
		for(int i = 0; i < n; i++)
			mynodes.printNode(i);
	}
}
