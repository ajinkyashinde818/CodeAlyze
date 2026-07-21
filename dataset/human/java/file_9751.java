import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	int root;
	Node[] T;
	int[] D;
	int[] H;
	void run() {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		T = new Node[n];
		
		for(int i = 0; i < n; i++) {
			T[i] = new Node(-1);
		}
		
		for(int i = 0; i < n; i++) {
			int id = sc.nextInt();
			int l = sc.nextInt();
			int r = sc.nextInt();
			T[id].left = l;
			T[id].right = r;
			if(T[id].left != -1) T[l].parent = id;
			if(T[id].right != -1) T[r].parent = id;
		}
		for(int i = 0; i < n; i++) {
			if(T[i].parent == -1) root = i;
		}
		
		//深さ
		Deque<Integer> deq = new ArrayDeque<>();
		D = new int[n];
		deq.push(root);
		while(!deq.isEmpty()) {
			int tmp = deq.pop();
			for(int i = 0; i < n; i++) {
				if(T[tmp].left == i) {
					deq.push(i);
					D[i] = D[tmp] + 1;
				}
			}
			for(int i = 0; i < n; i++) {
				if(T[tmp].right == i) {
					deq.push(i);
					D[i] = D[tmp] + 1;
				}
			}
		}
		
		//高さ
		H = new int[n];
		setHeight(root);
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++) {
			sb.append("node ");
			sb.append(i);
			sb.append(": parent = ");
			sb.append(T[i].parent);
			sb.append(", sibling = ");
			sb.append(getSibling(i));
			int deg = 0;
			if(T[i].right != -1) deg++;
			if(T[i].left != -1) deg++;
			sb.append(", degree = ");
			sb.append(deg);
			sb.append(", depth = ");
			sb.append(D[i]);
			sb.append(", height = ");
			sb.append(H[i]);
			sb.append(", ");
			if(T[i].parent == -1) sb.append("root\n");
			else if(T[i].left == -1 && T[i].right == -1) sb.append("leaf\n");
			else sb.append("internal node\n");
		}
		String s = sb.toString();
		System.out.print(s);
		
		sc.close();
	}
	
	int getSibling(int u) {
		if(T[u].parent == -1) return -1;
		if(T[T[u].parent].left != u && T[T[u].parent].left != -1) return T[T[u].parent].left;
		if(T[T[u].parent].right != u && T[T[u].parent].right != -1) return T[T[u].parent].right;
		return -1;
	}
	
	int setHeight(int u) {
		int h1 = 0;
		int h2 = 0;
		if(T[u].left != -1) h1 = setHeight(T[u].left) + 1;
		if(T[u].right != -1) h2 = setHeight(T[u].right) + 1;
		return H[u] = Math.max(h1, h2);
	}

	void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
class Node {
	int parent, left, right;
	public Node(int parent) {
		this.parent = parent;
	}
}
