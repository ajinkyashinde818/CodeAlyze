import java.util.ArrayList;
import java.util.Scanner;

class Node{
	int depth = 0;
	int height = 0;
	int degree = 0;
	int parent = -1;
	String type = "";
	int sibling = - 1;
	ArrayList<Integer> children = new ArrayList<Integer>();
} 

public class Main {
	
	private static Scanner src;
	public static Node[] tree;
	public static void main(String[] args) {
		src = new Scanner(System.in);
		int n = src.nextInt();
		tree = new Node[n];
		for(int i = 0; i < n; i++) tree[i] = new Node(); 
		for(int i = 0; i < n; i++) {
			int id = src.nextInt(); 
			Integer lc = src.nextInt(), rc = src.nextInt();
			if(lc != -1) {
				tree[id].children.add(lc);
				tree[lc].parent = id;
				tree[lc].sibling = rc;
			}
			if(rc != -1) {
				tree[id].children.add(rc);
				tree[rc].parent = id;
				tree[rc].sibling = lc;
			}
		}
		for(int i = 0; i < n; i++) {
			tree[i].degree = tree[i].children.size();
			if(tree[i].parent == -1) {
				setDepth(i, 0);
				setHeight(i);
			}
		}
		for(int i = 0; i < n; i++) {
			StringBuilder answ = new StringBuilder();
			answ.append("node ").append(i).append(": parent = ").append(tree[i].parent).append(", sibling = ")
			.append(tree[i].sibling).append(", degree = ").append(tree[i].degree).append(", depth = ")
			.append(tree[i].depth).append(", height = ").append(tree[i].height).append(", ");
			if(tree[i].parent == -1) { answ.append("root"); } 
			else if(tree[i].children.size() > 0) { answ.append("internal node"); }
			else answ.append("leaf");
			System.out.println(answ);
		}
	}
	static void setDepth(int i, int j) {
		tree[i].depth = j;
		for(int n = 0; n < tree[i].children.size(); n++) {
			setDepth(tree[i].children.get(n), j + 1);
		}
	}
	private static void setHeight(int i) {
		if(tree[i].children.size() == 0) return;
		int max = 0;
		for(int j = 0; j < tree[i].children.size(); j++) {
			setHeight(tree[i].children.get(j));
			if(tree[tree[i].children.get(j)].height > max) 
				max = tree[tree[i].children.get(j)].height;
			}
		tree[i].height = max + 1;
	}
}
