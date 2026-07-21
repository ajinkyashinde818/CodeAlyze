import java.util.*;
import java.math.*;
public class Main {
	static int r; 
	static int c;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int n = in.nextInt();
		int[] house = new int[n];
		for(int i = 0; i < n; i++) house[i] = in.nextInt();
		Arrays.sort(house);
		int ans = 0;
		if(n > 1) {
			ans = house[n - 1] - house[0];
			for(int i = 1; i < n; i++) {
				ans = Math.min(ans, (k - house[i]) + house[i - 1]);
			}
			for(int i = 0; i < n - 1 ; i++) {
				ans = Math.min(ans, house[i] + (k - house[i + 1]));
			}
		}
		System.out.println(ans);
	}
}
