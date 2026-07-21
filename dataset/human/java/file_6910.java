import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt(), n = sc.nextInt();
		int a[] = new int[n];
		int max = 0;
		for(int i = 0; i < n; ++i){
			a[i] = sc.nextInt();
			if(i > 0){
				max = Math.max(max, Math.abs(a[i] - a[i - 1]));
			}
		}
		max = Math.max(max, Math.abs(a[n - 1] - a[0] - k));
		sc.close();
		int ans = k - max;
		System.out.println(ans);
	}
}
