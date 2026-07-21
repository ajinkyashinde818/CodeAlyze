import java.util.Scanner;

public class Main {
	void run() {
		Scanner sc = new Scanner(System.in);
		
		//MCXI
		int[] ten = new int['z'];
		ten['m'] = 1000;
		ten['c'] = 100;
		ten['x'] = 10;
		ten['i'] = 1;
		
		for (int T = sc.nextInt() - 1; 0 <= T; T--) {
			char[] a = sc.next().toCharArray();
			char[] b = sc.next().toCharArray();
			
			int ka = 0, kb = 0;
			for (int i = 0; i < a.length; i++) {
				int k = 1;
				if ('0' <= a[i] && a[i] <= '9') k = a[i++] - '0';
				ka += k * ten[a[i]];
			}
			for (int i = 0; i < b.length; i++) {
				int k = 1;
				if ('0' <= b[i] && b[i] <= '9') k = b[i++] - '0';
				kb += k * ten[b[i]];
			}
			
			int k = ka + kb;
			String s = "";
			if (k / 1000 > 0) {
				s += k / 1000 > 1 ? "" + k / 1000 : "";
				s += "m";
			}
			k %= 1000;
			if (k / 100 > 0) {
				s += k / 100 > 1 ? "" + k / 100 : "";
				s += "c";
			}
			k %= 100;
			if (k / 10 > 0) {
				s += k / 10 > 1 ? "" + k / 10 : "";
				s += "x";
			}
			k %= 10;
			if (k / 1 > 0) {
				s += k / 1 > 1 ? "" + k / 1 : "";
				s += "i";
			}
			
			System.out.println(s);
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
