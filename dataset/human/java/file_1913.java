import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
	
	static int d , g ;
	static int []p;
	static int []c;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		d = sc.nextInt();
		g = sc.nextInt();
		
		p = new int [d];
		c = new int [d];
		
		for(int i = 0 ; i < d ; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		
		sc.close();
		
		solve();
	}
	
	static void solve() {
		Set<Integer>hs = new HashSet<Integer>();
		
		int min = 1000000000;
		int n = (int)Math.pow(2, d);
		
		for(int i = 0 ; i < n ;i++) {
			int sum = 0;
			int cnt = 0;
			for(int j = 0 ; j < d ;j++) {
				if((1 & i >> j) == 1) {
					sum += ((j+1) * 100 * p[j]) + c[j];
					cnt += p[j];
					hs.add(j);
				}
				
			}
			f:if(sum < g) {
			for(int k = d-1 ; k >= 0 ; k--) {
				if(!hs.contains(k)) {
					int temp = 0;
					while(true) {
						sum += (k+1) * 100;
						temp++;
						if(sum >= g || temp == p[k]) {
							cnt += temp;
							break;
						}
					}
					
					break f;
				}
			}			
		}	
			if(sum >= g) {
			min = Math.min(cnt, min);
			}
			hs.clear();
	}
		
		System.out.println(min);
		
		
	}
}
