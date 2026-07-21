import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	private static FastScanner sc = new FastScanner();

	public static void main(String[] args) {
		int n = sc.nextInt();

		Node_BT[] nodes = new Node_BT[n];
		for(int i=0; i<n; i++) {
			nodes[i] = new Node_BT();
		}

		for(int i=0; i<n; i++) {
			int id = sc.nextInt();
			int left = sc.nextInt();
			int right = sc.nextInt();
			nodes[id].left = left;
			nodes[id].right = right;

			if(left != -1) {
				nodes[left].parent = id;
				nodes[left].sibling = right;
			}
			if(right != -1) {
				nodes[right].parent = id;
				nodes[right].sibling = left;
			}
		}

		for(int i=0; i<n; i++) {
			if(nodes[i].parent == -1) {
				nodes[i].writeData(nodes, 0);
				break;
			}
		}

		StringBuilder ans = new StringBuilder();
		for(int i=0; i<n; i++) {
			ans.append("node ");
			ans.append(i);
			ans.append(": parent = ");
			ans.append(nodes[i].parent);
			ans.append(", sibling = ");
			ans.append(nodes[i].sibling);
			ans.append(", degree = ");
			ans.append(nodes[i].degree);
			ans.append(", depth = ");
			ans.append(nodes[i].depth);
			ans.append(", height = ");
			ans.append(nodes[i].height);
			ans.append(", ");
			ans.append(nodes[i].type);
			ans.append("\n");
		}
		System.out.print(ans);
	}

	static class Node_BT {
		int left;
		int right;
		int parent = -1;
		int sibling = -1;
		int degree = 0;
		int depth;
		int height;
		String type;

		int writeData(Node_BT[] nodes, int depth) {
			this.depth = depth;

			int h_left = -1;
			int h_right = -1;
			if(left != -1) {
				h_left = nodes[left].writeData(nodes, depth + 1);
				degree++;
			}
			if(right != -1) {
				h_right = nodes[right].writeData(nodes, depth + 1);
				degree++;
			}
			height = Math.max(h_left, h_right) + 1;



			if(parent == -1) {
				type = "root";
			} else if(height == 0) {
				type = "leaf";
			} else {
				type = "internal node";
			}

			return height;
		}
	}

	static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException  e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
