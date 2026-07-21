import java.io.*;
import java.math.*;
import java.util.*;
public class Main { 

	public static void main(String[] args) { //
		Scanner input = new Scanner(System.in);
		long N = input.nextLong();
		long ans = 0;
		while (N>1) {
			if (Prime(N)) {
				ans++;
				break;
			} 
			for (long i = 2; i <= Math.sqrt(N); i++) {
				long cnt = 0;
				long curTopLimit = 1;
				while (N%i==0) {
					N/=i;
					cnt++;
					if (cnt>=curTopLimit) {
						ans++;
						curTopLimit++;
						cnt=0;
					}
				}
			}
		}
		System.out.println(ans);
	}
	public static boolean Prime(long N) {
		for (long i = 2; i <= Math.sqrt(N); i++) {
			if (N%i==0) return false;
		}
		return true;
	}
}
