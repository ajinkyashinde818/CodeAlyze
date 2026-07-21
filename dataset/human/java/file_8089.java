import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

//		long ans2 = 0;
//		long ans = 0;
		long ans = 0;
//		String ans = "";

		Scanner sc = new Scanner(System.in);


		long a = sc.nextInt();
		long b = sc.nextInt();
//		int k = sc.nextInt();
//		String s = sc.next();
//		String t = sc.next();

//		String string = sc.next();
//		StringBuilder s = new StringBuilder(string);

		boolean f = false;

//

//		int[] b = new int[n];
//		int[][] aa = new int[h][w];
//		int[] bb = new int[n];
//		for (int i = 0; i < h; i++) {
//			for(int j = 0; j < w; j++) {
//				a[i][j] = sc.nextInt();
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			b[i] = sc.nextInt();
//			bb[i] = b[i];
//		}

		ans = lcm(a, b);


		System.out.println(ans);

		sc.close();
	}

	private static long gcd(long m, long n) {
	    if(m < n) return gcd(n, m);
	    if(n == 0) return m;
	    return gcd(n, m % n);
	}

	private static long lcm(long m, long n) {
	    return m * n / gcd(m, n);
	}
}
