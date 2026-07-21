import java.util.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.math.RoundingMode;
import java.math.BigDecimal;
 
 
 
public class Main{
	 public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] a = new int[n];
		long[] visit = new long[n];
		for(int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
			long count = 0;
			int now = 0;
			while(visit[now]==0) {
				count++;
				visit[now]=count;
				now = a[now]-1;
			}
			long loop = count+1-visit[now];
			//System.out.println(loop);
			if(k>=count) {
				long sub = count-loop;
				long circ = k-sub;
				circ %= loop;
				circ %= loop;
				int ans = 0;
				for(int i = 0; i < circ+sub; i++) {
					ans = a[ans]-1;
				}
				System.out.println(ans+1);
			}
			else {
				int ans = 0;
				for(int i = 0; i < k; i++) {
					ans = a[ans]-1;
				}
				System.out.println(ans+1);
			}
		}
}
