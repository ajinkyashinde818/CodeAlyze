import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		long f = 0;
		//
		if ( n % 2 == 1 ) {
			System.out.println(0);
		} else {
			for ( long m = 10; m <= n; m = m * 5 ) {
				f = f + ( n / m ) ;
			}
			System.out.println(f);
		}
	}
}
