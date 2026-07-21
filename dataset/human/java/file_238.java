import java.util.Scanner;

public class Main {
	Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();
	}

	void solve() {
		int n = nextInt();
		long[]a = new long[n];

		for(int i=0;i<n;i++)a[i]=nextLong();
		int less_zero=0;
		long min = 1L<<60;
		long sum = 0;
		for (int i=0;i<n;i++) {
	        if (a[i]<0)less_zero++;
	        min=min(min, abs(a[i]));
	        sum += abs(a[i]);
	    }
	    if (less_zero%2==0) println(sum);
	    else println(sum-(min*2));
	}

	private void println(Object s) {
		System.out.println(s);
	}

	private int nextInt() {
		return Integer.parseInt(sc.next());
	}
	private long nextLong() {
		return Long.parseLong(sc.next());
	}
	private String next() {
		return sc.next();
	}
	private long abs(long a) {
		return Math.abs(a);
	}
	private long min(long a,long b) {
		return Math.min(a,b);
	}
}
