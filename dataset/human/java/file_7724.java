import java.util.*;
 
public class Main { 
    public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[] to = new int[n+1];
		int[] moved = new int[n+1];
		for(int i=1; i<=n; i++){
			to[i] = sc.nextInt();
		}
		int now = 1;
		moved[now]++;
		int end = 0;
		int roopCount = 0;
		for(int i=0; i<=to.length; i++){
			if(moved[to[now]] > 0){
				end = to[now];
				roopCount++;
				break;
			}
			now = to[now];
			moved[now]++;
			roopCount++;
			if(k == roopCount){
				System.out.println(now);
				return;
			}
		}
		int roopStartCount = 0;
		if(end != 1){
			now = 1;
			for(int i=0; i<=to.length; i++){
				if(to[now] == end){
					roopStartCount++;
					break;
				} 
				now = to[now];
				roopStartCount++;
			}
		}
		roopCount -= roopStartCount;
		long mod = (k-roopStartCount)%roopCount;
		for(long i=mod; i>0; i--){
			end = to[end];
		}
		System.out.println(end);

	}
}
