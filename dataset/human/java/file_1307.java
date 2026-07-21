import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.next());
		int[] a = new int[n];
		long sumA = 0;
		long sumT = Integer.parseInt(sc.next());
		for (int i = 1; i < n; i++) {
			a[i] = Integer.parseInt(sc.next());
			sumA += a[i];
		}
		long diff = Math.abs(sumT - sumA);
		for (int i = 1; i < n - 1; i++) {
			sumT += a[i];
			sumA -= a[i];
			diff = Math.min(diff, Math.abs(sumT - sumA));
		}
		System.out.println(diff);
	}

}
