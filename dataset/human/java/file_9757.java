import java.util.*;

public class Main {
	Scanner sc = new Scanner(System.in);
	StringBuilder output = new StringBuilder();
	int n;
	node nodes[];
	int id,left,right;
	
	public void input() {
		n = sc.nextInt();
		nodes = new node[n];
		for(int i=0; i<n; i++) nodes[i] = new node(); 
	}
	
	public void solve() {
		for(int i=0; i<n; i++) {
			id = sc.nextInt();
			//left,rightはidの子
			left = sc.nextInt();
			right = sc.nextInt();
			//左右それぞれ、子があった場合は親にidを設定する
			if(left != -1) {nodes[left].parent = id;}
			if(right != -1) {nodes[right].parent = id;}
			//入力された子を二分木に登録する
			nodes[id].left = left;
			nodes[id].right = right;
			//兄弟の設定
			//left,rightが共に存在していないと兄弟とはいえない
			if(left != -1 && right != -1) {
				nodes[left].sibling = right;
				nodes[right].sibling = left;
			}
		}
		for(int i=0; i<n; i++) {nodes[i].height = height(i);}
		int root = 0;
		while(nodes[root].parent != -1) {root = nodes[root].parent;}
		depth(root,0);
	}
	
	public void depth(int id, int d) {
		int left = nodes[id].left;
		int right = nodes[id].right;
		if(left != -1) depth(left, d+1);
		if(right != -1) depth(right, d+1);
		nodes[id].depth = d;
	}
	public int height(int id) {
		if(id == -1) return -1;
		int left = nodes[id].left;
		int right = nodes[id].right;
		nodes[id].height = Math.max(height(left), height(right)) + 1;
		return nodes[id].height;
	}
	public void output() {
		for(int i=0; i<n; i++) {
			int num = 0;
			if(nodes[i].left != -1) num++;
			if(nodes[i].right != -1) num++;
			//節点番号
			output.append("node ").append(Integer.toString(i));
			//親
			output.append(": parent = ").append(Integer.toString(nodes[i].getParent()));
			//兄弟
			output.append(", sibling = ").append(Integer.toString( nodes[i].sibling ) );
			//子の数
			output.append(", degree = ").append(Integer.toString(num) );
			//深さ
			output.append(", depth = ").append( Integer.toString(nodes[i].depth) );
			//高さ
			output.append(", height = ").append( Integer.toString(nodes[i].height) ).append(", ");
			//節点の種類
			if(nodes[i].getParent() == -1) {output.append("root\n");}
			else if(num == 0) {output.append("leaf\n");}
			else {output.append("internal node\n");}
		}
		System.out.print( output.toString() );
	}
	
	public static void main(String[] args) {
		Main obj = new Main();
		obj.input();
		obj.solve();
		obj.output();
	}
}

class node{
	int parent; //親
	int left,right; //parentの子
	int sibling; //兄弟
	int depth;
	int height;
	node(){
		parent = -1;
		left = right = sibling = -1;
	}
	public int getParent() {return parent;}
	public void setParent(int parent) {this.parent = parent;}
}
