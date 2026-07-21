import java.util.Scanner;

public class Main{

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine());

		String[] tempA = sc.nextLine().split(" ");
		String[] tempB = sc.nextLine().split(" ");
		String[] tempC = sc.nextLine().split(" ");

		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		int ans = 0;

		for(int i = 0; i < n; i ++) {

			a[i] = Integer.parseInt(tempA[i]);
			b[i] = Integer.parseInt(tempB[i]);
			c[i] = i == n - 1 ? 0 : Integer.parseInt(tempC[i]);

		}

		for(int i = 0; i < n; i ++) {

			ans += b[a[i] - 1] ;

			if(i < n - 1 && a[i] == a[i + 1] - 1) {

				ans += c[a[i] - 1];

			}
		}

		System.out.println(ans);

	}

}
