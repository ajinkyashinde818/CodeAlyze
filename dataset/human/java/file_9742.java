import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Node[] nodes = new Node[n];
		for (int i = 0; i < n; i++) {
		    nodes[i] = new Node(i);
		}
		for (int i = 0; i < n; i++) {
		    int x = sc.nextInt();
		    int left = sc.nextInt();
		    int right = sc.nextInt();
		    nodes[x].left = left;
		    nodes[x].right = right;
		    if (left >= 0) {
		        nodes[left].sibling = right;
		        nodes[left].parent = x;
		    }
		    if (right >= 0) {
		        nodes[right].sibling = left;
		        nodes[right].parent = x;
		    }
		}
		for (Node x : nodes) {
		    if (x.parent == -1) {
		        set(nodes, x.idx, 0);
		        break;
		    }
		}
		StringBuilder sb = new StringBuilder();
		for (Node x : nodes) {
		    sb.append(x).append("\n");
		}
		System.out.print(sb);
	}
	
	static int set(Node[] nodes, int idx, int depth) {
	    nodes[idx].depth = depth;
	    int max = 0;
	    if (nodes[idx].left >= 0) {
	        max = Math.max(max, set(nodes, nodes[idx].left, depth + 1));
	    }
	    if (nodes[idx].right >= 0) {
	        max = Math.max(max, set(nodes, nodes[idx].right, depth + 1));
	    }
	    nodes[idx].height = max;
	    return max + 1;
	}
	
	static class Node {
	    int idx;
	    int parent;
	    int depth;
	    int height;
	    int sibling;
	    int left;
	    int right;

	    public Node(int idx) {
	        this.idx = idx;
	        parent = -1;
	        sibling = -1;
	        left = -1;
	        right = -1;
	    }
	    
	    private int getDegree() {
	        int ans = 0;
	        if (left >= 0) {
	            ans++;
	        }
	        if (right >= 0) {
	            ans++;
	        }
	        return ans;
	    }
	    
	    public String toString() {
	        StringBuilder sb = new StringBuilder();
	        sb.append("node ").append(idx).append(": parent = ");
	        sb.append(parent).append(", sibling = ").append(sibling).append(", degree = ").append(getDegree());
	        sb.append(", depth = ").append(depth).append(", height = ").append(height).append(", ");
	        if (parent == -1) {
	            sb.append("root");
	        } else if (getDegree() == 0) {
	            sb.append("leaf");
	        } else {
	            sb.append("internal node");
	        }
	        return sb.toString();
	    }
	}
}
