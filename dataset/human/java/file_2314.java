import java.util.*;
import java.io.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Math.*;

public class Main {

	int INF = 1 << 28;
	//long INF = 1L << 62;
	double EPS = 1e-10;

	void run() {
		Scanner sc = new Scanner(System.in);
		String cs = "";
		for(int i=0;i<26;i++) cs += (char) ('a' + i);
		for(int i=0;i<26;i++) cs += (char) ('A' + i);
		for(;;) {
			int n = sc.nextInt();
			if(n == 0) break;
			
			int[] a = new int[n];
			for(int i=0;i<n;i++) a[i] = sc.nextInt();
			String code = sc.next();
			String ret = "";
			for(int i=0;i<code.length();i++) {
				int p = 0;
				for(;p<cs.length();p++) if(cs.charAt(p) == code.charAt(i)) break;
				ret += cs.charAt((p + cs.length() - a[i%a.length]) % cs.length());
			}
			System.out.println(ret);
		}
	}

	void debug(Object... os) {
		System.err.println(Arrays.deepToString(os));
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
