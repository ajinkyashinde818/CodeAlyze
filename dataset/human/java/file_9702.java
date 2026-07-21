//API???????????????
import java.util.Scanner;
import java.io.IOException;
class Main {
  	public static void main(String[] args) throws IOException{
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();

		Nodes nodes = new Nodes();
		Node[] node = new Node[n];
		nodes.nodes = node;
		for(int i = 0;i < n;i++){
			node[i] = new Node(i);
		}
		
		for(int i = 0;i < n; i++){
			int id = scan.nextInt();
			int left = scan.nextInt();
			int right = scan.nextInt();
			if(left != -1) node[left].parent = id;
			if(right != -1) node[right].parent = id;
			node[id].left = left;
			node[id].right = right;
			if(left != -1 && right != -1){
				node[left].sibling = right;
				node[right].sibling = left;
			}
		}
		
		int root = 0;
		
		while(node[root].parent != -1){
			root = node[root].parent;
		}
		
		nodes.setDepth(root, 0);
		node[root].height = nodes.setHeight(root);
		
		for(int i = 0; i < n; i++){
			StringBuilder sb = new StringBuilder();
			int d = 0;
			if(node[i].left != -1) d++;
			if(node[i].right != -1) d++;
			
			sb.append("node " + i + ": parent = " + node[i].parent + ", sibling = " + node[i].sibling + ", degree = " + d + ", depth = " + node[i].depth + ", height = " + node[i].height + ", ");
			//????????????????????°
			if(node[i].parent == -1) sb.append("root\r\n");
			//???????????????????????????????????°
			else if(d == 0) sb.append("leaf\r\n");
			//????????\???
			else sb.append("internal node\r\n");
			System.out.print(sb);
		}
	}
}

class Node{
	int id;
	int parent = -1;
	int left = -1;
	int right = -1;
	int sibling = -1;
	int depth = -1;
	int height = -1;

	public Node(int id) {
		this.id = id;
	}
}

class Nodes{
	/*
	List<Node> nodes;
	/*/
	Node[] nodes;
	/**/
	
	//-1??????????????§??±????????£?????????
	public void setDepth(int id, int d){
		int l = nodes[id].left;
		int r = nodes[id].right;
		if(l != -1) setDepth(l, d + 1);
		if(r != -1) setDepth(r, d + 1);
		nodes[id].depth = d;
	}
	
	public int setHeight(int id){
		if(id == -1) return -1;
		
		int l = nodes[id].left;
		int r = nodes[id].right;
		nodes[id].height = Math.max(setHeight(l), setHeight(r)) + 1; 
		return nodes[id].height;
	}
}
