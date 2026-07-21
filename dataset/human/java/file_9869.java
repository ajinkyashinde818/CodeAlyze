import java.io.IOException;
	import java.util.ArrayList;
	import java.util.HashMap;
	import java.util.Scanner;
	import java.util.Stack;
	
	public class Main {
		public static class pair implements Comparable<pair> {
			int id;
			int ans;
	
			pair(int x, int y) {
	
				id = x;
				ans = y;
	
			}
	
			public pair() {
	
			}
	
			public int compareTo(pair o) {
				// TODO Auto-generated method stub
	
				return this.id - o.id;
			}
		}
	
	//	static int mod = (int) 998244353.;
		static int mod = (int) 1e9 + 7;
		static ArrayList<Integer> gr[];
		static int[][] ar;
		static Scanner sc = new Scanner(System.in);
		static int pri[] = new int[(int) 1e6 + 5];
		static StringBuilder out = new StringBuilder();
	
		 static int dp[];
	
		 static int []c;
		public static void main(String[] args) throws IOException {
			int t = 1;// sc.nextInt();
	
			while (t-- > 0) {
			int n=sc.nextInt();
			int m=sc.nextInt();
			int k=sc.nextInt();
			c=new int[n];
			ar=new int [n][m];
			dp=new int [m];
			
			
			for(int i=0;i<n;i++) {
				c[i]=sc.nextInt();
				
				for(int j=0;j<m;j++) {
					ar[i][j]=sc.nextInt();
					dp[j]=k;
				}
			}
			solve(n-1,0);
			if(ans!=Integer.MAX_VALUE)
			System.out.println(ans);
			else System.out.println(-1);
			
			}
	
			
			
			System.out.println(out);
		}
		static int ans=Integer.MAX_VALUE;
		static void solve(int id,int sum) {
			if(id<0) {
				boolean f=true;;
				for(int i=0;i<ar[0].length;i++) {
				    if(dp[i]>0)return;
				}
				ans=Math.min(ans, sum);
				return;
				
			}
			for(int i=0;i<ar[0].length;i++) {
				dp[i]-=ar[id][i];
			}
			
			  solve(id-1,sum+c[id]);
			  for(int i=0;i<ar[0].length;i++) {
					dp[i]+=ar[id][i];
				}
			  solve(id-1,sum);
			
		}
	}
