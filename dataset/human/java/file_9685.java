import java.io.BufferedReader;
//import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		Node[] node = input();
		print(node);
	}
	
	public static Node[] input() throws NumberFormatException, IOException{
		//System.setIn(new FileInputStream("./ALDS1_7_B-in1.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Node[] node = new Node[n];
		
		for(int i = 0; i < n; ++i) {
			node[i] = new Node(i);
		}
		
		for(int i = 0; i < n; ++i) {
			String[] t = br.readLine().split(" ");
			int id = Integer.parseInt(t[0]);
			
			int c1 = Integer.parseInt(t[1]);
			int c2 = Integer.parseInt(t[2]);
			
			if(c1 != -1){
				node[id].child.add(node[c1]);
				node[c1].parent = node[id];
			}
			if(c2 != -1){
				node[id].child.add(node[c2]);
				node[c2].parent = node[id];
			}
			if(c1 != -1 && c2 != -1){
				node[c1].sibling = node[c2];
				node[c2].sibling = node[c1];
			}
		}
		return node;
	}

	public static void print(Node[] node){
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < node.length; ++i) {
			// example
			// node 0: parent = -1, sibling = -1, degree = 2, depth = 0, height = 3, root
			sb.append("node " + node[i].id);
			sb.append(": parent = " + node[i].parent.id);
			sb.append(", sibling = " + node[i].sibling.id);
			sb.append(", degree = " + node[i].getDegree());
			sb.append(", depth = " + node[i].getDepth());
			sb.append(", height = " + node[i].getHeight());
			sb.append(", " + node[i].getType());
			sb.append("\n");

		}
		System.out.print(sb);
	}
}

class Node {
	public int id;
	public Node parent;
	public ArrayList<Node> child = new ArrayList<Node>();
	public Node sibling;
	public Node(int id){
		this.id = id;
		if(id != -1){
			parent = sibling = new Node(-1);
		}
	}

	public int getDepth(){
		if(parent.id == -1){
			return 0;
		}else{
			return parent.getDepth() + 1;
		}
	}
	
	public int getHeight(){
		if(child.size() == 0){
			return 0;
		}else if(child.size() == 1){
			return child.get(0).getHeight() + 1;
		}else{
			return Math.max(child.get(0).getHeight(), child.get(1).getHeight()) + 1;
		}
	}
	
	public int getDegree(){
		return child.size();
	}
	
	public String getType(){
		if(parent.id == -1){
			return "root";
		}else if(child.size() == 0){
			return "leaf";
		}else{
			return "internal node";
		}
		
	}
}
