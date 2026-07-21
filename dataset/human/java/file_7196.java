import java.io.*;
import java.util.*;

public class Main extends PrintWriter {
	Main() { super(System.out, true); }
	Scanner sc = new Scanner(System.in);
	public static void main(String[] $) {
		Main o = new Main(); o.main(); o.flush();
	}

	void main() {
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] aa = new int[n];
		for (int i = 0; i < n; i++)
			aa[i] = sc.nextInt();
		int gap = aa[0] + k - aa[n - 1];
		for (int i = 1; i < n; i++)
			gap = Math.max(gap, aa[i] - aa[i - 1]);
		println(k - gap);
	}
}
