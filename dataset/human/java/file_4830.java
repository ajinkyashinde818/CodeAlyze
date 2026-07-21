import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		try(Scanner sc = new Scanner(System.in)) {
//			System.out.println(f(10));
//			System.out.println(f(40));
			
			long n = sc.nextLong();
			
			if ( n % 2 == 1) {
				System.out.println(0);
				return;
			}
			
			long ans = 0;
//			for(long i = 2 ; i <= n ; i+=2 ) {
//				//TLE
//				count += countZero(i);
//			}
//			
//			System.out.println(count);
			
//			int len = String.valueOf(n).length();
			
//			System.out.println(len);
			
//			//10のみを考えるのはよくない
//			long upper = 0;
//			for(int i = len - 1 ; i > 0 ; i-- ) {
//				long div = (long)Math.pow(10, i);
//				
//				long currentCount = (n / div);
//				System.out.println(currentCount );
//				ans += currentCount;
//			}
			
			long div = 10;
			while( n / div > 0 ) {
				ans += n / div;
				div *= 5;
			}
			
			System.out.println(ans);
		}
	}
	
	public static long countZero(long n) {
		
		long count = 0;
		
		while(n > 0 && n % 10 == 0) {
			count++;
			n = n / 10;
		}
		
		return count;
	}
	
	public static long f(long n) {
		if ( n < 2) {
			return 1;
		}
		return n * f(n-2);
	}

}
