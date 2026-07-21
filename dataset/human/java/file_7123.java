import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int k = sc.nextInt();
		int n = sc.nextInt();
		int a[] = new int[n];
		
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		
		int d[] = new int[n];
		d[0] = a[0] + (k - a[n - 1]);
		int max = d[0];
		
		for(int i = 1; i < n; i++) {
			d[i] = a[i] - a[i - 1];
			max = Math.max(max, d[i]);
		}
		
		System.out.println(k - max);
	}

}
