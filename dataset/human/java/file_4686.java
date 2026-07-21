// practice with kaiboy
import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
	Main() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		Main o = new Main(); o.main(); o.flush();
	}

	void main() {
		byte[] cc = sc.next().getBytes();
		int n = cc.length;
		int dp0 = 0, dp1 = 1;
		for (int i = 0; i < n; i++) {
			int d = cc[i] - '0';
			int dq0 = Math.min(dp0 + d, dp1 + 10 - d);
			int dq1 = Math.min(dp0 + d + 1, dp1 + 10 - d - 1);
			dp0 = dq0;
			dp1 = dq1;
		}
		println(dp0);
	}
}
