import java.io.*;
import java.util.*;
import java.math.BigInteger;
public class Main {

    final static boolean fileIO = false;
    final static boolean DEBUG = false;
    final static String input = "input.txt";
    final static String output = "output.txt";
    
    public static void main(String args[]) throws Exception {

		InputStream is = null;
		OutputStream os = null;
		if (fileIO) {
			is = new FileInputStream("input.txt");
			os = new FileOutputStream("output.txt");
		} else {
			is = System.in;
			os = System.out;
		}
		InputReader in = new InputReader(is);
		PrintWriter out = new PrintWriter(os);
		new Task().solve(in, out);
		out.close();	

	}
	
	static class Task {
		
		public void solve(InputReader in, PrintWriter out) {
			char s[] = in.nextString("\n").toCharArray();
			char t[] = in.nextString("\n").toCharArray();
			Arrays.sort(s);
			Arrays.sort(t);
			int state = 0;
			for (int i = 0, j = t.length - 1; state == 0 && i < s.length && j >= 0; ++i, --j) {
				if (s[i] < t[j]) {
					state = 1;
				} else if (s[i] > t[j]) {
					state = 2;
				}
			}
			if (state == 0) {
				if (s.length < t.length) {
					state = 1;
				} else {
					state = 2;
				}
			}
			out.println(state == 1 ? "Yes" : "No");


		}
	}

	static class InputReader {
	
		private StringTokenizer tokenizer;
		private BufferedReader reader;

		public InputReader(InputStream is) {
			tokenizer = null;
			reader = new BufferedReader(new InputStreamReader(is), 32768);
		}

		public String nextString(String delim) {
			String ans = null;
			if (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					String line = reader.readLine();
					if (line != null) {
						tokenizer = new StringTokenizer(line, delim);
						ans = tokenizer.nextToken();
					} else {
						ans = null;
					}
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			} else {
				ans = tokenizer.nextToken();
			}
			return ans;
		}
	
		public Integer nextInt() {
			return Integer.parseInt(nextString(" "));		
		}
	}
}
