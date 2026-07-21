import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws Exception {
		// TODO ?????????????????????????????????????????????
		BufferedReader br =
				new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());

		Node[] T = new Node[n];
		for (int i=0; i < n; i++) {
			T[i] = new Node(i);
		}

//		Node dammy = new Node(-1);

		for (int i=0; i < n; i++) {
			String[] info = br.readLine().split(" ");
			int id = Integer.parseInt(info[0]);
			int left = Integer.parseInt(info[1]);
			int right = Integer.parseInt(info[2]);

			if (left == -1) {
				if (right == -1) {
					T[id].degree = 0;
//					T[id].childs = new Node[] {dammy};
				} else {
					T[id].degree = 1;
					T[id].childs = new Node[] {T[right]}; //{null, T[right]};

					T[right].parent = T[id];
				}
			} else {
				if (right == -1) {
					T[id].degree = 1;
					T[id].childs = new Node[] {T[left]}; //{T[left], null};

					T[left].parent = T[id];
				} else {
					T[id].degree = 2;
					T[id].childs = new Node[] {T[left], T[right]};

					T[right].parent = T[id];
					T[left].parent = T[id];

					T[left].sibling = T[right];
					T[right].sibling = T[left];
				}
			}
		}

		for (int i=0; i < n; i++) {
			if (T[i].parent == null) {setdepth(T[i]);}
			if (T[i].degree == 0) {setheight(T[i]);}
		}

		for (Node u : T) {
			System.out.println(u);
		}

	}

	public static class Node {
		int id;
		Node parent;
		Node sibling;
		Node[] childs;
		int degree;
		int depth;
		int height;

		public Node(int id) {
			this.id = id;
//			childs = new Node[2];
		}

		@Override
		public String toString() {
			StringBuilder sb = new StringBuilder();

			sb.append("node " + id);

			if (parent == null) sb.append(": parent = -1");
			else sb.append(": parent = " + parent.id);

			if (sibling == null) sb.append(", sibling = -1");
			else sb.append(", sibling = " + sibling.id);

			sb.append(", degree = " + degree);

			sb.append(", depth = " + depth);

			sb.append(", height = " + height);

			if (parent == null) sb.append(", root");
			else if (degree != 0) sb.append(", internal node");
			else sb.append(", leaf");

			return sb.toString();
		}
	}

	public static void setdepth(Node x) {
		if (x.degree == 0) return;
		for (Node c : x.childs) {
			c.depth = x.depth + 1;
		}
		for (Node c : x.childs) {
			setdepth(c);
		}
	}

	public static void setheight(Node x) {
		if (x.parent == null) return;
		if (x.height+1 <= x.parent.height) return;
		x.parent.height = x.height + 1;
		setheight(x.parent);
	}
}
