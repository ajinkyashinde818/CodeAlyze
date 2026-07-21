import java.util.Arrays;
import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);

		int k = stdIn.nextInt();
		int n = stdIn.nextInt();
		int[] a = new int[n];

		for(int i = 0; i < n; i++) {
			a[i] = stdIn.nextInt();
		}


		long[]dif = new long[n];
		dif[0] = (k - a[n-1])+a[0];

		for(int i = 1; i < n; i++) {
			dif[i] = (a[i]-a[i-1]);

		}

//		dif[n] = a[0] - a[n-1];

		Arrays.sort(dif);

		long ans = 0;
		for(int i = 0; i < n-1; i++) {
			ans += dif[i];
		}

		System.out.println(ans);
	}

}
