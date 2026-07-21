import java.io.*;
import java.math.*;
import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int N = input.nextInt();
		long[] pref = new long[N+1];
		long ans = Long.MAX_VALUE;
		for (int i = 1; i <= N; i++) {
			pref[i] = pref[i-1]+input.nextInt();
		}
		long TOTAL_SUM = pref[N];
		for (int L = 1; L < N; L++) {
			long left = pref[L];
			long right = TOTAL_SUM-left;
			ans = Math.min(ans, Math.abs(left-right));
		}
		System.out.println(ans);
	}
}
