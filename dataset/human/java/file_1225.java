import java.util.*;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		long a[] = new long[n];
		long sum[] = new long[n+1];

		sum[0]=0;
		for(int i=0; i<n; i++) {
			a[i]=sc.nextLong();
			sum[i+1] = sum[i]+a[i];
		}

		long ans = Long.MAX_VALUE;
		for(int i=1; i<n; i++) {
			long x = sum[i];
			long y = sum[n]-sum[i];
			ans = Math.min(Math.abs(x-y), ans);
		}
		System.out.println(ans);
		sc.close();
	}





}
