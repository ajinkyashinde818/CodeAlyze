import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n  = Integer.parseInt(br.readLine());
		Node[] nodes = setInfo(n,br);
		pirntInfo(n,nodes);

	}

	private static void pirntInfo(int n,Node[] nodes){
		for(int i = 0 ; i < n ; i++){
			System.out.printf("node %d: parent = %d, "
					+ "sibling = %d, degree = %d, depth = %d, height = %d, %s\r\n"
					,i,nodes[i].parent,nodes[i].sibling,nodes[i].degree,nodes[i].depth,nodes[i].height,getType(i,nodes));
		}
	}

	private static String getType(int i,Node[] nodes){
		if(nodes[i].parent == -1){
			return "root";
		}else if(nodes[i].degree == 0){
			return "leaf";
		}else{
			return "internal node";
		}
	}

	private static Node[] setInfo(int n,BufferedReader br) throws Exception{

		Node[] nodes = new Node[n];
		for(int i = 0 ; i < n ; i++ ) nodes[i] = new Node();
		setParentAndSibling(n,br,nodes);
		int rootIndex = getRootIndex(nodes);
		setDepth(rootIndex,nodes,0);
		setHight(rootIndex,nodes);
		return nodes;
	}

	private static int setHight(int index,Node[] nodes){
		int left = 0;
		int right = 0;
		if(nodes[index].left != -1){
			left = setHight(nodes[index].left,nodes) + 1;
		}

		if(nodes[index].right != -1){
			right = setHight(nodes[index].right,nodes) + 1;
		}

		return nodes[index].height = Math.max(left,right);
	}


	private static int getRootIndex(Node[] nodes){
		int i = 0;
		while(nodes[i].parent != -1){
			i++;
		}
		return i;
	}

	private static void setDepth(int index,Node[] nodes,int depth){
		nodes[index].depth = depth;
		if(nodes[index].left != -1){
			setDepth(nodes[index].left,nodes,depth+1);
		}

		if(nodes[index].right != -1){
			setDepth(nodes[index].right,nodes,depth+1);
		}
	}

	private static void setParentAndSibling(int n,BufferedReader br,Node[] nodes) throws Exception{
		String[] infos;
		int id;
		int left;
		int right;

		for(int i = 0 ; i < n ; i++ ){
			infos = br.readLine().split(" ");
			id = StoI(infos[0]);
			left = StoI(infos[1]);
			right = StoI(infos[2]);


			if(left != -1){
				//???????????±????¨????
				nodes[id].degree++;
				nodes[id].left = left;
				//???????????±????¨????
				nodes[left].parent = id;
				nodes[left].sibling = right;
			}

			if(right != -1){
				//???????????±????¨????
				nodes[id].degree++;
				nodes[id].right = right;
				//???????????±????¨????
				nodes[right].parent = id;
				nodes[right].sibling = left;
			}
		}

	}

	private static int StoI(String s){
		return Integer.parseInt(s);
	}

}

class Node{
	int node;
	int parent;
	int sibling;
	int degree;
	int depth;
	int height;
	int right;
	int left;
	String type;

	Node(){
		parent = -1;
		sibling = -1;
		right = -1;
		left = -1;
		degree = 0;
	}
}
