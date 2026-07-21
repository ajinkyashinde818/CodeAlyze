import java.util.Scanner;


	public class Main {
		
		
		static int n;
		static int m;
		static int x;
		static int[] c = new int[12];
		static int[][] a = new int[12][12];
		static int cur_price;
		static int[] cur_a = new int[12];
		static int ret = Integer.MAX_VALUE;

		public static void main(String[] args) {

			Scanner sc = new Scanner(System.in);
	        
			n = sc.nextInt();
			m = sc.nextInt();
			x = sc.nextInt();
			
			for(int i=0;i<n;i++) {
				c[i] = sc.nextInt();
				for(int j=0;j<m;j++) {
					a[i][j] = sc.nextInt();
				}
			}
			
			dfs(0);
			
			if(ret == Integer.MAX_VALUE) {
				System.out.println(-1);
			}else {
				System.out.println(ret);
			}
			
		}
		
		static void dfs(int i) {
			if(i==n) {
				return;
			}
			
			cur_price += c[i];
			
			boolean isOk = true;
			
			for(int j=0;j<m;j++) {
				cur_a[j] += a[i][j];
				if(cur_a[j]<x) {
					isOk = false;
				}
			}
			
			if(isOk) {
				ret = Math.min(ret, cur_price);
			}
			
			dfs(i+1);
			
			cur_price -= c[i];
			
			for(int j=0;j<m;j++) {
				cur_a[j] -= a[i][j];
			}
			
			dfs(i+1);
		}
		
		
	}
