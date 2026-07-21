import java.util.*;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Node u[] = new Node[n];
		for(int i=0; i<n; i++){
			int id = sc.nextInt();
			u[id] = new Node();
			u[id].id = id;
			u[id].left = sc.nextInt();
			u[id].right = sc.nextInt();
			u[id].p = -1;
			u[id].s = -1;
			u[id].deg = 0;
			u[id].type = "leaf";
			if(u[id].left != -1){
				u[id].deg++;
				u[id].type = "internal node";
			}
			if(u[id].right != -1){
				u[id].deg++;
				u[id].type = "internal node";
			}
		}

		for(int i=0; i<n; i++){
			if(u[i].left != -1){
				u[u[i].left].p = u[i].id;
			}
			if(u[i].right != -1){
				u[u[i].right].p = u[i].id;
			}
			if(u[i].left != -1 && u[i].right != -1){
				u[u[i].left].s = u[i].right;
				u[u[i].right].s = u[i].left;
			}
		}

		for(int i=0; i<n; i++){
			if(u[i].p == -1){
				u[i].type = "root";
				if(u[i].left != -1){
					setDep(u, u[i].left, 1);
				}
				if(u[i].right != -1){
					setDep(u, u[i].right, 1);
				}
			}
			if(u[i].deg == 0){
				if(u[i].p != -1){
					setH(u, u[i].p, 1);
				}
			}
		}

		StringBuilder sb = new StringBuilder();
		for(int i=0; i<n; i++){
			sb.append("node "      + u[i].id   + ": ");
			sb.append("parent = "  + u[i].p    + ", ");
			sb.append("sibling = " + u[i].s    + ", ");
			sb.append("degree = "  + u[i].deg  + ", ");
			sb.append("depth = "   + u[i].dep  + ", ");
			sb.append("height = "  + u[i].h    + ", ");
			sb.append(               u[i].type + "\n");
		}
		System.out.print(sb.toString());
	}

	static void setDep(Node u[], int c, int dep){
		u[c].dep = dep;
		dep++;
		if(u[c].left != -1){
			setDep(u, u[c].left, dep);
		}
		if(u[c].right != -1){
			setDep(u, u[c].right, dep);
		}
	}

	static void setH(Node u[], int p, int h){
		if(h < u[p].h) h = u[p].h;
		else           u[p].h = h;
		h++;
		if(u[p].p != -1){
			setH(u, u[p].p, h);
		}
	}
}

class Node{
	int id;
	int left;
	int right;
	int p;
	int s;
	int deg;
	int dep;
	int h;
	String type;
}
