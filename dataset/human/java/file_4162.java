import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in Actual solution is at the top
 */

public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		solver.solve(1, in, out);
		out.close();
	}

	static class Task {
		public void solve(int testNumber, InputReader in, PrintWriter out) {
			int N = in.nextInt();
			int[] A = new int[N];
			int[] B = new int[N];
			int[] C = new int[N - 1];
			for(int i = 0; i < N; i++) {
				A[i] = in.nextInt();
			}
			for(int i = 0; i < N; i++) {
				B[i] = in.nextInt();
			}
			for(int i = 0; i < N - 1; i++) {
				C[i] = in.nextInt();
			}
			int total = 0;
			int tmp = 0;
			for(int i = 0; i < N; i++) {
				total += B[A[i] - 1];
				if(i != 0) {
					if(A[i] - 1 == A[i - 1]) {
						total += C[A[i] - 2];
					}	
				}
			}
			System.out.println(total);
			
		}
	}
	
	static boolean permutation_2(String s, String t){
        if(s.length() != t.length()){
            return false;
        }
        
        int[] letters = new int[256]; //文字コードの仮定;
        
        char[] s_array = s.toCharArray();  
        for(char c:s_array){
            letters[c]++;
        }
        
        for(int i=0;i<t.length();i++){
            int c = (int)t.charAt(i);
            if(--letters[c] < 0){
                return false;
            }
        }
        return true;
    }

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream), 32768);
			tokenizer = null;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public char nextChar() {
			return next().charAt(0);
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}
}
