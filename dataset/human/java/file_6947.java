import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int k = scan.nextInt();
		int n = scan.nextInt();

		int[] a = new int[n];
		int[] b = new int[n];

		int i;
		for(i = 0; i < n; i++)
			a[i] = scan.nextInt();

		b[0] = a[n - 1] - a[0];
		for(i = 1; i < n; i++) {
			int end = i - 1;
			if(a[i] > a[end])
				b[i] = (a[end] + k) - a[i];
			else
				b[i] = a[end] - a[i];

		}

		long ans = Integer.MAX_VALUE;
		for(i = 0; i < n; i++) {
			if(b[i] < ans) {
				ans = b[i];
			}
		}

		System.out.println(ans);
	}
}
