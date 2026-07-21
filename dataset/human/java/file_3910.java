import java.util.BitSet;
import java.util.LinkedList;
import java.util.Scanner;

public class Main{
	public static String[] token;
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		while(true){
			int n = in.nextInt();
			if(n == 0) return;
			int depth = 1;
			token = new String[n];
			token[0] = in.next();
			Node[] node = new Node[n];
			node[0] = new Node(0, null, 0);
			Node parent = node[0];
			for(int i=1; i<n; i++){
				token[i] = in.next();
				int dot = parse(i);
				if(depth < dot){
					parent = parent.edge.getLast();
					depth++;
				}
				while(depth > dot){
					parent = parent.parent;
					depth--;
				}
				parent.createEdge(new Node(i, parent, depth));
			}
			dfs(node[0], new BitSet(n));
		}
	}
	
	public static void dfs(Node parent, BitSet bs){
		parent.out(bs);
		bs.set(parent.depth);
		for(Node v: parent.edge){
			if(v == parent.edge.getLast()){
				bs.clear(parent.depth);
			}
			dfs(v, bs);
		}
	}
	
	public static int parse(int id){
		int dot = 0;
		while(token[id].charAt(dot) == '.') dot++;
		token[id] = token[id].substring(dot, token[id].length());
		return dot;
	}
}

class Node{
	int id;
	Node parent;
	LinkedList<Node> edge;
	int depth;
	public Node(int id, Node parent, int depth){
		edge = new LinkedList<Node>();
		this.id = id;
		this.parent = parent;
		this.depth = depth;
	}
	
	public void createEdge(Node nd){
		edge.add(nd);
	}
	
	public void out(BitSet bs){
		StringBuilder sb = new StringBuilder();
		for(int i=0; i<depth; i++){
			if(i==depth-1){
				sb.append('+');
			}else if(bs.get(i)){
				sb.append('|');
			}else sb.append(' ');
		}
		sb.append(Main.token[id]);
		System.out.println(sb.toString());
	}
}
