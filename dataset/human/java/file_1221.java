import java.util.Scanner;


	public class Main {
		
		

		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
			
			int n = sc.nextInt();
			long[] a = new long[n+1];
			long sum = 0;
			
			
			for(int i=1;i<=n;i++) {
				a[i] = sc.nextLong();
				sum += a[i];
			}
			
			long x = 0;
			long y = sum;
			long ret = Long.MAX_VALUE;
			
			for(int i=1;i<n;i++) {
				x += a[i];
				y -= a[i];
				ret = Math.min(ret, Math.abs(x-y));
			}
			
			System.out.println(ret);
		}
		
	}
