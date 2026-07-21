import java.util.*;
import java.math.*;
public class Main {
	static int x;
	static int ans;
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		long k = in.nextLong();
		int[] tp = new int[n + 1];
		int[] check = new int[n + 1];
		boolean[] check2 = new boolean[n + 1];
		for(int i = 1; i < n + 1; i++) tp[i] = in.nextInt();
		int cnt = 0;
		int cur = 1;
		int interval = 0;
		boolean flag = true;
		while(cnt < k) {
			if(cnt > 0) {
				if(check2[cur] == true) {
					interval = cnt - check[cur];
					flag = false;
					break;
				}
			}
			check[cur] = cnt;
			check2[cur] = true;
			cur = tp[cur];
			cnt += 1;
		}
		if(flag == true) {
			System.out.println(cur);
		}else {
			k -= cnt;
			k = k % interval;
			while(k > 0) {
				cur = tp[cur];
				k -= 1;
			}
			System.out.println(cur);
		}
	}
}
