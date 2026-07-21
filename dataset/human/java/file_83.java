import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] a = new long[n];
		int cnt = 0;
		int flag = 0;
		for(int i = 0; i < n; i++){
			a[i] = sc.nextLong();
			if(a[i] == 0){
				flag = 1;
			}else if(a[i] < 0){
				cnt++;
			}
		}
		if(cnt%2 == 0 || flag == 1){
			long ans = 0;
			for(int i = 0; i < n; i++){
				ans += Math.abs(a[i]);
			}
			System.out.print(ans);
		}else{
			long ans = 0;
			long min = 1000000005;
			for(int i = 0; i < n; i++){
				ans += Math.abs(a[i]);
				min = Math.min(Math.abs(a[i]),min);
			}
			min = min*2;
			ans -= min;
			System.out.print(ans);
		}
	}
}
