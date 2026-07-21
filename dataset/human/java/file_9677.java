import java.util.Scanner;
import java.util.Arrays;

class Main {
	public static void main(String args[]) {
		run();
	}
	public static void run() {
		Scanner scanner = new Scanner(System.in);
		int  num = scanner.nextInt();//要素数
		Node[] nodes = new Node[num];
		boolean[] root = new boolean[num];
		Arrays.fill(root, true);
		
		//要素ごとの親と子の関係構築
		for(int i = 0; i < num; i ++ ){
			int id = scanner.nextInt();
			int left = scanner.nextInt();
			int right = scanner.nextInt();
			if (left != -1){
				root[left] = false;
			}
			if (right != -1){
				root[right] = false;
			}
			nodes[id] = new Node(id, left, right);
		}
		
		//ノードごとにデータ作成
		for( int i = 0; i < num ; i ++ ){
			if( root[i] ){
				Binarytree( nodes, -1, i, 0 );
				break;
			}
		}		
		
		output(nodes);//出力関数
		
		scanner.close();
	}
	
	public static void output(Node[] nodes){
	   //出力
	   StringBuilder sb = new StringBuilder("");
		for (Node node: nodes) {
			sb.append("node ").append(node.id);
			sb.append(": parent = ").append(node.parent);
			sb.append(", sibling = ").append(node.sibling);
			sb.append(", degree = ").append(node.degree);
			sb.append(", depth = ").append(node.depth);
			sb.append(", height = ").append(node.height);
			sb.append(", ").append(node.type);
			sb.append("\n");
		}
		System.out.print(sb);
	}
	//ツリー作成
	public static int Binarytree(Node[] nodes, int parent, int id, int depth){ 
		if (id == -1) {	//根の判定
			return -1;
		}
		
		Node node = nodes[id];
		node.parent = parent;
		
		//子供判定
		if (node.left != -1) {
			nodes[node.left].sibling = node.right;
		}
		if (node.right != -1) {
			nodes[node.right].sibling = node.left;
		}
		
		//深さと高さ
		node.degree = ((node.left == -1) ? 0 : 1) + ((node.right == -1) ? 0 : 1);
		node.depth = depth;
		node.height = Math.max(Binarytree(nodes, id, node.left, depth + 1), 
			Binarytree(nodes, id, node.right, depth + 1)) + 1;
		
		//種類付け
		if (node.parent == -1) {
			node.type = "root";
		}else if (node.left == -1 && node.right == -1) {
			node.type = "leaf";
		}else {
			node.type = "internal node";
		}
 
		return node.height;
	}
}
class Node{
	public int id;
	public int parent;
	public int sibling = -1;
	public int degree;
	public int depth;
	public int height;
	public String type;
	public int left;
	public int right;
	
	public Node(int id, int left, int right) {
		this.id = id;
		this.left = left;
		this.right = right;
	}
	
}
