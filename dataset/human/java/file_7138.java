import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		int leng = (k - a[n-1]) + (a[0] - 0);
		int maxLeng = leng;
		for (int i = 0; i < n - 1; i++) {
			int tmpLeng = a[i + 1] - a[i];
			leng += tmpLeng;
			if (tmpLeng > maxLeng) {
				maxLeng = tmpLeng;
			}
		}
		System.out.println(leng - maxLeng);
		sc.close();
	}
}
