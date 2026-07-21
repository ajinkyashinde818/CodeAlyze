import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[200000];
		for(int i = 0; i < n; i++){
			a[i] = sc.nextInt();
		}
		sc.close();

		int max = 0;
		for(int i = 0; i < n; i++) {
			int d;
			if(i == n - 1) {
				d = k + a[0] - a[i];
			}else {
				d = a[i + 1] - a[i];
			}
			max = Math.max(max, d);
		}


		System.out.print(k - max);
	}
}
