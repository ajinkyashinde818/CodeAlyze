import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

	static long expo(long base, long exp) {
		long t = 1L;
		while (exp > 0) {
			if (exp % 2 != 0)
				t = (t * base);

			base = (base * base);
			exp /= 2;
		}
		return t;
	}

	public static void main(String args[]) throws Exception {
		MyScanner sc = new MyScanner();
		PrintWriter pr = new PrintWriter(System.out);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int ar[] = new int[n + 1];

		ar[0] = 0;
		HashSet<Integer> selfloop = new HashSet<>();
		for (int i = 1; i <= n; i++) {
			ar[i] = sc.nextInt();
			if (ar[i] == i)
				selfloop.add(i);
		}

		int cyclelen = 0;
		int cyclestart = 0;
		HashSet<Integer> set = new HashSet<>();
		int source = 1;
		set.add(1);
		boolean flag = false;
		while (cyclelen < k) {

			source = ar[source];
			cyclelen++;
			if (selfloop.contains(source)) {
				flag = true;
				break;
			}
			if (set.contains(source)) {
				cyclestart = source;
				break;
			} else
				set.add(source);

		}

		if (flag) {
			System.out.println(source);
			return;
		}

		if (cyclelen == k) {
			System.out.println(source);
			return;
		}

		ArrayList<Integer> cycle = new ArrayList<>();
		cycle.add(cyclestart);
		set.clear();
		set.add(cyclestart);
		int a = cyclestart;
		while (true) {

			a = ar[a];
			if (set.contains(a))
				break;
			else {
				set.add(a);
				cycle.add(a);
			}
		}

		/*
		 * for(int i : cycle) System.out.print(i + " ");
		 */

		k -= cyclelen;
		pr.println(cycle.get((int) (k % cycle.size())));
		pr.close();
	}

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
