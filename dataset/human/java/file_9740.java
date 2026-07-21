import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {

	Node[] nodes;
	int[] sibling;
	int[] depth;
	int[] height;

	private static class Node{

		int parent = -1;
		int left = -1;
		int right = -1;
	}

	public int getHeight(int n){
		if(n == -1){
			return 0;
		}
		int h = 0;
		h = Math.max(h,getHeight(nodes[n].left) + 1);
		h = Math.max(h,getHeight(nodes[n].right) + 1);

		return h;
	}

	public void solve() {
		int n = nextInt();

		nodes = new Node[n];
		sibling = new int[n];
		depth = new int[n];
		height = new int[n];

		for(int i = 0;i < n;i++){
			nodes[i] = new Node();
		}

		for(int i = 0;i < n;i++){
			int id = nextInt();
			int left = nextInt();
			int right = nextInt();

			nodes[id].left = left;
			nodes[id].right = right;

			if(left != -1){
				nodes[left].parent = id;
			}

			if(right != -1){
				nodes[right].parent = id;
			}
		}

		for(int i = 0;i < n;i++){
			int parent = nodes[i].parent;

			if(parent == -1){
				sibling[i] = -1;
			}else{
				if(nodes[parent].left != i){
					sibling[i] = nodes[parent].left;
				}else{
					sibling[i] = nodes[parent].right;
				}
			}
		}


		for(int i = 0;i < n;i++){
			int parent = nodes[i].parent;
			int d = 0;
			while(parent != -1){
				parent = nodes[parent].parent;
				d++;
			}
			depth[i] = d;
		}

		for(int i = 0;i < n;i++){
			height[i] = getHeight(i) - 1;
		}


		for(int i = 0;i < n;i++){
			out.print("node " + i + ": ");
			out.print("parent = " + nodes[i].parent + ", ");
			out.print("sibling = " + sibling[i] + ", ");

			int degree = 0;

			if(nodes[i].left != -1){
				degree++;
			}

			if(nodes[i].right != -1){
				degree++;
			}

			out.print("degree = " + degree + ", ");
			out.print("depth = " + depth[i] + ", ");
			out.print("height = " + height[i] + ", ");
			if(nodes[i].parent == - 1){
				out.print("root");
			}else if(nodes[i].left == -1 && nodes[i].right == -1){
				out.print("leaf");
			}else{
				out.print("internal node");
			}
			out.println();
		}

	}

	public static void main(String[] args) {
		out.flush();
		new Main().solve();
		out.close();
	}

	/* Input */
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out);
	private final byte[] buffer = new byte[2048];
	private int p = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (p < buflen)
			return true;
		p = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (buflen <= 0)
			return false;
		return true;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrint(buffer[p])) {
			p++;
		}
		return hasNextByte();
	}

	private boolean isPrint(int ch) {
		if (ch >= '!' && ch <= '~')
			return true;
		return false;
	}

	private int nextByte() {
		if (!hasNextByte())
			return -1;
		return buffer[p++];
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = -1;
		while (isPrint((b = nextByte()))) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
}
