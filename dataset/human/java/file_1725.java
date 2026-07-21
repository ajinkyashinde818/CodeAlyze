import java.util.*;
import java.io.*;

public class Main {
    static final int MOD = 1000000007;
	public static void main (String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		char[] arr = br.readLine().toCharArray();
		int[] counts = new int[26];
		for (char c : arr) {
		    counts[c - 'a']++;
		}
		long ans = 1;
		for (int x : counts) {
		    ans *= x + 1;
		    ans %= MOD;
		}
		ans--;
		ans += MOD;
		ans %= MOD;
		System.out.println(ans);
    }
}
