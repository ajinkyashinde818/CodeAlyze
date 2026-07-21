import java.util.*;

public class Main {
 	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		long total = 0;
		int min = Integer.MAX_VALUE;
		int count = 0;
		for (int i = 0; i < n; i++) {
		    arr[i] = sc.nextInt();
		    total += Math.abs(arr[i]);
		    min = Math.min(min, Math.abs(arr[i]));
		    if (arr[i] < 0) {
		        count++;
		    }
		}
		if (count % 2 == 1) {
		    total -= min * 2;
		}
	    System.out.println(total);
   }
}
