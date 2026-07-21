import java.util.Scanner;


	public class Main {
		
		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
			
			long k = sc.nextLong();
			long n = sc.nextLong();
			long[] a = new long[(int)n];
			
			for(int i=0;i<n;i++) {
				a[i] = sc.nextLong();
			}
			long dis = 0;
			for(int i=1;i<n;i++) {
				dis = Math.max(dis, a[i]-a[i-1]);
			}
			
			dis = Math.max(dis, Math.abs(k-a[(int)n-1]+a[0]));
			
			System.out.println(k-dis);
			
	    }
		
	}
