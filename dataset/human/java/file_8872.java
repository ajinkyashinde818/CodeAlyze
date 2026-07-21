import java.io.File;
import java.util.Properties;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static Properties pps = System.getProperties();
	static boolean dbg = true;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = ni(3);

		System.out.println(Solve(a));

	}

	private static int Solve(int[] a) {
		// TODO Auto-generated method stub
		int k = Math.min(a[0], a[1]);
		while (true) {

			if (a[1] % k == 0 && a[0] % k == 0) {
				if (--a[2] == 0) {
					return k;
				}

			}
			--k;

		}

	}

	public static void out(String str) {

		if (dbg)
			System.out.println(str);
	}

	public static void out(int str) {

		if (dbg)
			System.out.println(str);
	}

	public static int ni() {
		sc.nextLine();
		return sc.nextInt();

	}

	public static String ns() {

		return sc.nextLine();
	}

	public static int[] ni(int k) {
		int[] res = new int[k];
		for (int i = 0; i < k; i++)
			res[i] = sc.nextInt();
		sc.nextLine();
		return res;
	}

	public static String[] ns(int k) {
		String[] res = new String[k];
		for (int i = 0; i < k; i++)
			res[i] = sc.nextLine();
		return res;
	}

	public static int[][] ni(int a, int b) {
		int[][] res = new int[a][b];
		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++)
				res[i][j] = sc.nextInt();
		sc.nextLine();
		return res;
	}
}
