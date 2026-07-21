import java.io.*;
import java.math.*;
import java.util.*;
public class Main { //Prime FACTORIZE!
//1e18 = 5^18*2^18 (Simply consider 5s since all factors are even anyway)
	public static void main(String[] args) { 
		Scanner input = new Scanner(System.in);
		long N = input.nextLong();
		if (N%2==1) System.out.println(0);
		else {
			long cnt = 0;
			long div = 5;
			cnt+=N/div/2;
			while (div<N) {
				div*=5;
				cnt+=(N/div)/2; //Odd multiples of 5 are excluded
			}
			System.out.println(cnt);
		}
	}
}
