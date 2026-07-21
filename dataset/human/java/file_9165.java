import java.util.Scanner;
import java.util.Comparator;
import java.util.Arrays;
import java.util.ArrayList;



public class Main {

	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		if (M == 0) {
			if(N == 1) {
				System.out.println(1);
			}
			else {
				long [] ans = new long[N+1];
				ans[0] = 1;
				ans[1] = 1;

				for (int i = 2; i<N+1;i++) {
						ans[i]=(ans[i-1]+ans[i-2])%1000000007;
				}
				System.out.println(ans[N]);
			}
		}
		else {
			int [] a = new int[M];
			for (int i = 0; i< M; i++) {
				a[i] = sc.nextInt();
			}
			if(N == 1) {
				System.out.println(1);
			}
			else {
				long [] ans = new long[N+1];
				ans[0] = 1;
				int tmp = 0;
				if(a[tmp]==1) {
					ans[1] = 0;
					if(M-1 != 0) {
						tmp++;
					}
					
				}
				else {
					ans[1] = 1;
				}
				for (int i = 2; i<N+1;i++) {
					if(a[tmp]==i) {
						ans[i] = 0;
						if(tmp<M-1) {
							tmp++;
						}
					}
					else {
						ans[i]=(ans[i-1]+ans[i-2])%1000000007;
					}
				}
				System.out.println(ans[N]);
			}
		}
		
	}
}
