import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextInt();
		long[] ints = new long[n];
		int[] values = new int[n];
		for (int i = 0; i < n; i++) {
		    ints[i] = sc.nextInt();
		    values[i] = sc.nextInt();
		}
		long max = 0;
		long base = 0;
		long next = 0;
		for (int i = 0; i < 35; i++) {
		    if (base >= k) {
		        break;
		    }
		    long target = (k ^ next) | base;
		    base = next;
		    next = next * 2 + 1;
		    if (target > k) {
		        continue;
		    }
		    long total = 0;
		    for (int j = 0; j < n; j++) {
		        if ((target | ints[j]) <= target) {
		            total += values[j];
		        }
		    }
		    max = Math.max(total, max);
		}
	    long total = 0;
	    for (int j = 0; j < n; j++) {
	        if ((k | ints[j]) <= k) {
	            total += values[j];
	        }
	    }
	    max = Math.max(total, max);
	    System.out.println(max);
	}
}
