import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.StringTokenizer;

public class Main {

	static class BinaryTrees {
		public void binarytrees (InputReader ir) {
			
			int n = ir.nextInt();
			Node[] node = new Node[n];
			for (int i = 0; i < n; i++) {
				node[i] = new Node();
			}
			
			for (int i = 0; i < n; i++) {
				int id = ir.nextInt();
				node[id].left = ir.nextInt();
				node[id].right = ir.nextInt();
				if (node[id].left != -1 && node[id].right != -1) {
					node[id].degree = 2;
				} else if (node[id].left != -1 || node[id].right != -1) node[id].degree = 1;
			}
			
			Parent (node, n);
			Sibling (node, n);
			
			for (int i = 0; i < n / 2; i++) {
				Depth (node, n);
				Height (node, n);
			}
			
			StringBuilder sb = new StringBuilder();
			
			for (int i = 0; i < n; i++) {
				sb.append("node ").append(Integer.toString(i))
				.append(": parent = ").append(node[i].parent)
				.append(", sibling = ").append(node[i].sibling)
				.append(", degree = ").append(node[i].degree)
				.append(", depth = ").append(node[i].depth)
				.append(", height = ").append(node[i].height);
				
				if (node[i].parent == -1) {
					sb.append(", root\n");
				} else if (node[i].degree > 0) {
					sb.append(", internal node\n");
				} else {
					sb.append(", leaf\n");
				}
			}			
			System.out.print(sb);
		}
		
		static void Parent (Node[] node, int n) {
			
			for (int i = 0; i < n; i++) {
				if (node[i].degree == 2) {
					node[node[i].left].parent = i;
					node[node[i].right].parent = i;
				} else if (node[i].degree == 1) {
					if (node[i].left != -1) node[node[i].left].parent = i;
					else node[node[i].right].parent = i;
				}
			}
			
		}
	
		static void Sibling (Node[] node, int n) {
			
			for (int i = 0; i < n; i++) {
				if ( node[i].parent != -1) {
					if (node[node[i].parent].left == i && node[node[i].parent].right != -1) {
						node[i].sibling = node[node[i].parent].right;
					} else if (node[node[i].parent].right == i && node[node[i].parent].left != -1) {
						node[i].sibling = node[node[i].parent].left;
					}
							
				}
			}
			
		}

		static void Depth (Node[] node, int n) {
			
			for (int i = 0; i < n; i++) {
				if (node[i].degree == 2) {
					node[node[i].left].depth = node[i].depth + 1;
					node[node[i].right].depth = node[i].depth + 1;
				} else if (node[i].left != -1) {
					node[node[i].left].depth = node[i].depth + 1;
				} else if (node[i].right != -1) {
					node[node[i].right].depth = node[i].depth + 1;
				}
			}
		}
		
		static void Height (Node[] node, int n) {
			
			for (int i = 0; i < n; i++) {
				if (node[i].degree == 2) {
					node[i].height = Math.max(node[node[i].left].height + 1, node[node[i].right].height + 1);
				} else if (node[i].left != -1) {
					node[i].height = node[node[i].left].height + 1;
				} else if(node[i].right != -1) {
					node[i].height = node[node[i].right].height + 1;
				} 
			}
			
		}
	}
	
	static class Node {
		int parent;
		int sibling;
		int degree;
		int left;
		int right;
		int height;
		int depth;
		public Node() {
			parent = -1;
			sibling = -1;
			degree = 0;
 			left = -1;
			right = -1;
			depth = 0;
			
		}
		
	}
	
	static class InputReader {
		BufferedReader br;
		StringTokenizer st;
		
		public String nextString() {
			
			 while (!st.hasMoreTokens()) {
	                try {
	                    st = new StringTokenizer(br.readLine(), " ");
	                } catch (IOException e) {
	                    throw new InputMismatchException();
	                }
	            }
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(nextString());
		}
					
		public InputReader (InputStream inputStream) {
			br = new BufferedReader (new InputStreamReader (inputStream));
			st = new StringTokenizer ("");
		}
		
	}
	
	public static void main (String[] args) {
		InputStream inputStream = System.in;
		InputReader in = new InputReader (inputStream);
		BinaryTrees obj = new BinaryTrees();
		obj.binarytrees(in);
	}
}
