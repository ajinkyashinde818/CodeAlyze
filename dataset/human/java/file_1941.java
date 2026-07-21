import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)), true);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.flush();
		out.close();
	}
}

class Pair {
	int first;
	int second;
	int pos;

	Pair(int first, int second, int pos) {
		this.first = first;
		this.second = second;
		this.pos = pos;
	}
}

class TaskB {

	public void solve(int testNumber, InputReader in, PrintWriter pw) {
		int D = in.nextInt();
		int G = in.nextInt();
		int d[] = new int[D];
		int c[] = new int[D];
		for (int i = 0; i < D; i++) {
			d[i] = in.nextInt();
			c[i] = in.nextInt();
		}
		int ans = Integer.MAX_VALUE;
		for (int mask = 0; mask < (1 << D); mask++) {
			int sum = 0;
			int rem_max = -1;
			int num = 0;
			for (int i = 0; i < D; i++) {
				if (((mask >> i) & 1) == 1) {
					sum += (100 * (i + 1) * d[i] + c[i]);
					num += d[i];
				} else {
					rem_max = i;
				}
			}
			if (sum < G) {
				int num1 = 100 * (rem_max + 1);
				int need = (G - sum + num1 - 1) / num1;
				if (need > d[rem_max]) {
					continue;
				}
				num += need;
			}
			ans = Math.min(ans, num);
		}
		pw.println(ans);

	}

	int __gcd(int a, int b) {
		if (b == 0)
			return a;
		return __gcd(b, a % b);

	}

	public int getInt(int num) {
		int ret = -1;
		switch (num) {
		case 0:
			ret = 6;
			break;
		case 1:
			ret = 2;
			break;
		case 2:
			ret = 5;
			break;
		case 3:
			ret = 5;
			break;
		case 4:
			ret = 4;
			break;
		case 5:
			ret = 5;
			break;
		case 6:
			ret = 6;
			break;
		case 7:
			ret = 3;
			break;
		case 8:
			ret = 7;
			break;
		case 9:
			ret = 6;
			break;
		}
		return ret;
	}

	public int isPow(long num) {
		int count = 0;
		while (num > 0) {
			num /= 2;
			count++;
		}
		return count;
	}
}

class InputReader {
	BufferedReader br;
	StringTokenizer st;

	public InputReader(InputStream in) {
		br = new BufferedReader(new InputStreamReader(in));
		st = null;
	}

	public String next() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return st.nextToken();
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
