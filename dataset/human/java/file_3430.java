import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return str;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		BigInteger nextBigIntger() {
			BigInteger bb = new BigInteger(next());
			return bb;
		}
	}

	public static void main(String[] args) {
		FastReader sc = new FastReader();
		HashMap<Character, Integer> map = new HashMap<>();
		char[] aa = sc.nextLine().toCharArray();
		boolean flag = true;
		for (int i = 0; i < aa.length; i++) {
			if (aa[i] == '9') {
				flag = true;
				break;
			} else
				flag = false;
		}
		if(flag)
			System.out.println("Yes");
		else
			System.out.println("No");
	}
}
