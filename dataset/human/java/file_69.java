import java.util.Scanner;

public class Main {
	Scanner sc = new Scanner(System.in);

	void run() {
		int q = sc.nextInt();
		for (;;) {
			if (q == 0)
				break;
			String s = sc.next();
			String ss[] = s.split("\\B");
			int[] ds = new int[8];
			for (int i = 0; i < ss.length; i++) {
				ds[i] = Integer.parseInt(ss[i], 16);
			}
			StringBuilder bs = new StringBuilder();
			for (int i = 0; i < 8; i++) {
				bs.append(d2b(ds[i]));
			}
			StringBuilder ans = new StringBuilder();
			if (bs.charAt(0) == '1')
				ans.append("-");
			int z = 0;
			for (int i = 1; i <= 24; i++) {
				int b = bs.charAt(i) - '0';
				z += b << (24 - i);
			}
			double[] fs = { 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625,
					0.0078125 };
			double r = 0.0;
			for (int i = 0; i < 7; i++) {
				if (bs.charAt(25 + i) == '1') {
					r += fs[i];
				}
			}
			ans.append(z);
			ans.append(".");
			String[] rr = Double.toString(r).split("\\.");
			ans.append(rr[1]);
			System.out.println(ans.toString());
			q--;
		}
	}

	String d2b(int n) {
		StringBuilder sb = new StringBuilder();
		for (int i = 3; i >= 0; i--) {
			if (n - (1 << i) >= 0) {
				sb.append(1);
				n -= 1 << i;
			} else {
				sb.append(0);
			}
		}
		return sb.toString();
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
