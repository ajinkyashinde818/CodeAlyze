import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int k = sc.nextInt();
		int n = sc.nextInt();

		int[] a = new int[n];

		for (int i=0; i<n; i++){
			a[i] = sc.nextInt();
		}

		int maxKyori=0;
		for (int i=0; i<n; i++){
			int kyori;
			if (i == n-1){
				kyori = a[0] + k - a[i];
			} else {
				kyori = a[i+1] - a[i];
			}
			maxKyori = Math.max(maxKyori, kyori);
		}
		System.out.println(k - maxKyori);
	}
}
