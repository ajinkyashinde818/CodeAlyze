import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	static final PrintStream out = System.out;
	static Scanner sc = new Scanner(System.in);
	static final long Mod = 1000_000_007L;
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
		System.exit(0);
	}

	void solve() {
		int K = nextInt();
		int S = nextInt();

		int cnt = 0;
		for(int i=0;i<=K;i++) {
			for(int j=0;j<=K;j++) {
				int num = i+j;
				if(num + K >= S && num <= S) {
					cnt++;
				}else if(num > S) {
					break;
				}
			}
		}

		out.println(cnt);
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
	public long nextLong() {
		return Long.parseLong(next());
	}
	public String next() {
		return sc.next();
	}

}
