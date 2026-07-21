import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		long total = 0;
		for (int i = 0; i < n; i++) {
		    arr[i] = sc.nextInt();
		    total += arr[i];
		}
		long sum = 0;
		long min = Long.MAX_VALUE;
		for (int i = 0; i < n - 1; i++) {
		    sum += arr[i];
		    min = Math.min(min, Math.abs(total - sum * 2));
		}
	    System.out.println(min);
	}
}
