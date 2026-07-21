//--- pC ---//
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
	public static void main (String[] args) throws java.lang.Exception {
		new Solution();
	}
}
class Solution {
	Scanner scanner;

	int a_idx = 0;
	int b_idx = 0;
	int idx_cnt = 0;

	public Solution() {
		scanner = new Scanner(System.in);

		// scanner.nextLine();
		while (scanner.hasNext()) {
			run_case();
		}
	}
	private void run_case() {
		// scanner.nextLine();
		String line = scanner.nextLine();

		// int N = Integer.parseInt(line);
		int a = Integer.parseInt(line.split("\\s+")[0]);
		int b = Integer.parseInt(line.split("\\s+")[1]);

		long res = lcm(a, b);
		System.out.println(res);
		return;
	}

	private int[] strToIntArray(String str) {
	    String[] vals = str.split("\\s+");
	    int sz = vals.length;
	    int[] res = new int[sz];
	    for (int i=0; i<sz; i++) {
	        res[i] = Integer.parseInt(vals[i]);
	    }
	    return res;
	}
	private long gcd(long a, long b) {
	    if (b == 0) return a;
	    else return gcd(b, a%b);
	}
	private long lcm(long a, long b) {
	    return (a / gcd(a, b) * b);
	}

}
