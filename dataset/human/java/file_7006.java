import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int prev = 0;
		int maxDis = 0;
		int first = 0;
		for (int i=0; i<n; i++) {
			int x = sc.nextInt();
			if (i == 0) {
				first = x;
			}
			maxDis = Math.max(x - prev, maxDis);
			prev = x;
		}
		System.out.println(k - Math.max(maxDis, first + k - prev));
		sc.close();
	}

}
