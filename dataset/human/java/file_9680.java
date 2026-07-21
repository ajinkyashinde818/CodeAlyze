import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

	public static void main(String[] args) throws IOException {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskX solver = new TaskX();
		solver.solve(1, in, out);
		out.close();
	}

	static class TaskX {
		public void solve(int testNumber, InputReader in, PrintWriter out) {

			int n = in.nextInt();
			int[] hei = new int[n];
			int[] deg = new int[n];
			int[] dep = new int[n];
			String[] type = new String[n];
			int[] sib = new int[n];
			Node[] nodes = new Node[n];
			for (int i = 0; i < n; i++) {
				nodes[i] = new Node();
			}
			for (int i = 0; i < n; i++) {
				int v = in.nextInt();
				int left = in.nextInt();
				int right = in.nextInt();
				nodes[v].left = left;
				nodes[v].right = right;
				if (left != -1) {
					nodes[left].parent = v;
				}
				if (right != -1) {
					nodes[right].parent = v;
				}
			}

			for (int u = 0; u < n; u++) {
				hei[u] = getHeight(nodes, u);
				deg[u] = getDegree(nodes, u);
				dep[u] = getDepth(nodes, u);
				type[u] = getTypr(nodes, u);
				sib[u] = getSibling(nodes, u);
			}

			// print
			StringBuffer sb = new StringBuffer();
			for (int i = 0; i < n; i++) {
				sb.append("node ").append(i).append(": parent = ");
				sb.append(nodes[i].parent).append(", sibling = ").append(sib[i]);
				sb.append(", degree = ").append(deg[i]).append(", depth = ");
				sb.append(dep[i]).append(", height = ").append(hei[i]);
				sb.append(", ").append(type[i]);
				if (i == n - 1) {
					continue;
				}
				sb.append("\n");
			}
			out.println(sb.toString());
		}
	}
	static int getHeight(Node[] nodes, int u) {
		int h1 = 0, h2 = 0;
		if (nodes[u].left != -1) {
			h1 = getHeight(nodes, nodes[u].left) + 1;
		}
		if (nodes[u].right != -1) {
			h2 = getHeight(nodes, nodes[u].right) + 1;
		}
		return Math.max(h1, h2);
	}

	static int getDegree(Node[] nodes, int u) {
		int count = 0;
		if (nodes[u].left != -1) count++;
		if (nodes[u].right != -1) count++;
		return count;
	}

	static int getDepth(Node[] nodes, int u) {
		int depth = 0;
		if (nodes[u].parent != -1) {
			depth = getDepth(nodes, nodes[u].parent) + 1;
		}
		return depth;
	}

	static int getSibling(Node[] nodes, int u) {
		int sibling = -1;
		if (nodes[u].parent != -1 && nodes[nodes[u].parent].left != u) {
			sibling = nodes[nodes[u].parent].left;
		} else if (nodes[u].parent != -1 && nodes[nodes[u].parent].right != u) {
			sibling = nodes[nodes[u].parent].right;
		}
		return sibling;
	}

	static String getTypr(Node[] nodes, int u) {
		String type = null;
		if (nodes[u].parent == -1) {
			type = "root";
		} else if (nodes[u].left == -1 && nodes[u].right == -1) {
			type = "leaf";
		} else {
			type = "internal node";
		}
		return type;
	}

	static class Node {
		int parent, left, right;
		public Node() {
			this.parent = -1;
			this.left = -1;
			this.right = -1;
		}
	}

	static class ArrayUtils {
		public static Map<Integer, Integer> getCountMap(int[] array) {
			Map<Integer, Integer> map = new TreeMap<>();
			for (int x : array)
				map.merge(x, 1, Integer::sum);
			return map;
		}
	}

	static class InputReader {
		BufferedReader in;
		StringTokenizer tok;

		public String nextString() {
			while (!tok.hasMoreTokens()) {
				try {
					tok = new StringTokenizer(in.readLine(), " ");
				} catch (IOException e) {
					throw new InputMismatchException();
				}
			}
			return tok.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(nextString());
		}

		public long nextLong() {
			return Long.parseLong(nextString());
		}

		public int[] nextIntArray(int n) {
			int[] res = new int[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextInt();
			}
			return res;
		}

		public long[] nextLongArray(int n) {
			long[] res = new long[n];
			for (int i = 0; i < n; i++) {
				res[i] = nextLong();
			}
			return res;
		}

		public InputReader(InputStream inputStream) {
			in = new BufferedReader(new InputStreamReader(inputStream));
			tok = new StringTokenizer("");
		}

	}


}
