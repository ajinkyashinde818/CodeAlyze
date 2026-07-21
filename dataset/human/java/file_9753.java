import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private class Node {
		int id, parent=-1, left=-1, right=-1, sibling=-1, depth, height=-1;
		public Node(int id) {
			this.id = id;
		}
		public String toString() {
			StringBuilder sb = new StringBuilder();
			sb.append("node " + id + ": ");
			sb.append("parent = " + parent + ", ");
			sb.append("sibling = " + sibling + ", ");
			sb.append("degree = " + getDegree() + ", ");
			sb.append("depth = " + depth + ", ");
			sb.append("height = " + height + ", ");
			if (parent == -1) {
				sb.append("root");
			} else if (getDegree() == 0) {
				sb.append("leaf");
			} else {
				sb.append("internal node");
			}
			return sb.toString();
		}
		private int getDegree() {
			int degree = 0;
			if (left != -1) degree++;
			if (right != -1) degree++;
			return degree;
		}
	}
	public static void main(String[] args) throws IOException {
		new Main().run();
	}
	private void run() throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		Node[] nodes = new Node[n];
		for (int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(reader.readLine());
			int id = Integer.parseInt(st.nextToken());
			int left = Integer.parseInt(st.nextToken());
			int right = Integer.parseInt(st.nextToken());
			if (nodes[id] == null) {
				nodes[id] = new Node(id);
			}
			nodes[id].left = left;
			nodes[id].right = right;
			if (left != -1 && nodes[left] == null) {
				nodes[left] = new Node(left);
			}
			if (right != -1 && nodes[right] == null) {
				nodes[right] = new Node(right);
			}
			if (left != -1) {
				nodes[left].sibling = right;
				nodes[left].parent = id;
			}
			if (right != -1) {
				nodes[right].sibling = left;
				nodes[right].parent = id;
			}
		}
		reader.close();
		
		int rootId = -1;
		for (int i = 0; i < n; i++) {
			if (nodes[i].parent == -1) {
				rootId = nodes[i].id;
				break;
			}
		}
		
		setDepth(nodes, rootId);
		setHeight(nodes, rootId);
		
		for (int i = 0; i < n; i++) {
			System.out.println(nodes[i]);
		}
	}
	
	private void setDepth(Node[] nodes, int id) {
		if (nodes[id].left != -1) {
			nodes[nodes[id].left].depth = nodes[id].depth + 1;
			setDepth(nodes, nodes[id].left);
		}
		if (nodes[id].right != -1) {
			nodes[nodes[id].right].depth = nodes[id].depth + 1;
			setDepth(nodes, nodes[id].right);
		}
	}
	
	private void setHeight(Node[] nodes, int id) {
		if (nodes[id].right != -1) {
			setHeight(nodes, nodes[id].right);
		}		
		if (nodes[id].left != -1) {
			setHeight(nodes, nodes[id].left);
		}
		if (nodes[id].getDegree() == 0) {
			nodes[id].height = 0;
		}
		if (nodes[id].left != -1) {
			nodes[id].height = Math.max(nodes[id].height, nodes[nodes[id].left].height + 1);
		}
		if (nodes[id].right != -1) {
			nodes[id].height = Math.max(nodes[id].height, nodes[nodes[id].right].height + 1);
		}
	}
}
