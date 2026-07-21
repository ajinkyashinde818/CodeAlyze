import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();
		int a[] = new int[n];
		long sub[] = new long[n+1];
		for(int i=0; i<n; i++) {
			a[i]=sc.nextInt();
		}
		long max=0;
		for(int i=1; i<n; i++) {
			sub[i]=Math.abs(a[i]-a[i-1]);
			max = Math.max(max, sub[i]);
		}
		sub[n] = Math.abs(a[0]+k-a[n-1]);
		max = Math.max(max, sub[n]);
		System.out.println(k-max);
		sc.close();
	}
}
