import java.util.Scanner;
public class Main {
private static Scanner s = new Scanner(System.in);

public static void main(String[] args) {
	 int n = s.nextInt();
     Node[] nodes = new Node[n];
     for (int i = 0; i < n; i++) {
         nodes[i] = new Node(i);
     }
     for (int i = 0; i < n; i++) {
         Node node = nodes[s.nextInt()];
         int left = s.nextInt();
         if (left != -1) node.setL(nodes[left]);
         int right = s.nextInt();
         if (right != -1) node.setR(nodes[right]);
         node.setSib();
     }
     Node root = null;
     for (int i = 0; i < n; i++) {
         if (nodes[i].parent == null) {
             root = nodes[i];
             break;
         }
     }
     root.setDep(0);
     for (int i = 0; i < n; i++) {
         nodes[i].setHei(0);
     }
     StringBuilder sb = new StringBuilder();
     for (int i = 0; i < n; i++) {
         sb.append("node ");
         sb.append(nodes[i].id);
         sb.append(": parent = ");
         if(nodes[i].parent == null) {
        	 sb.append(-1);
         }else {
        	 sb.append(nodes[i].parent.id);
         }
         sb.append(", sibling = ");
         if(nodes[i].sibling ==null) {
        	 sb.append(-1);
         }else {
        	 sb.append(nodes[i].sibling.id);
         }
         sb.append(", degree = ");
         sb.append(nodes[i].deg);
         sb.append(", depth = ");
         sb.append(nodes[i].dep);
         sb.append(", height = ");
         sb.append(nodes[i].hei);
         sb.append(", ");
         if (nodes[i].parent == null) {
             sb.append("root");
         } else {
             if (nodes[i].l == null && nodes[i].r == null) {
                 sb.append("leaf");
             } else {
                 sb.append("internal node");
             }
         }
         sb.append("\n");
     }
     System.out.print(sb);
 }
}


class Node{
	int id,deg,dep,hei;
	Node parent,sibling,l,r;

	Node(int id){
		this.id = id;
		this.deg = 0;
		this.dep = 0;
		this.hei = 0;
		}

	void setL(Node node) {
		l = node;
		l.parent = this;
		deg++;
	}

	void setR(Node node) {
		r = node;
		r.parent = this;
		deg++;
	}

	void setSib() {
		if(l != null && r != null) {
			l.sibling = r;
			r.sibling = l;
		}
	}

	void setDep(int dep){
		this.dep = dep;
		if(l != null)l.setDep(dep + 1);
		if(r != null)r.setDep(dep + 1);
	}

	void setHei(int hei) {
		if(hei >= this.hei) this.hei = hei;
		if(parent != null)parent.setHei(this.hei + 1);
	}

	}
