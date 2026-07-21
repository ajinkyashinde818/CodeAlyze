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
		static int[] ar;
		static Scanner sc = new Scanner(System.in);
		static int pri[] = new int[(int) 1e6 + 5];
		static StringBuilder out = new StringBuilder();
	
		// static long dp[];
	
		public static void main(String[] args) throws IOException {
			int t = 1;// sc.nextInt();
	
			while (t-- > 0) {
				int n = sc.nextInt();
				long k = sc.nextLong();
	
				ar = new int[n + 1];
				HashMap<Integer, Integer> hm = new HashMap<>();
				for (int i = 1; i <= n; i++) {
					ar[i] =sc.nextInt();
				}
				int j = 1;
				int cnt = 1;
				long val = 0;
				while (true) {
					if (k == 0)
						break;
					if (hm.containsKey(j)) {
						val =cnt- hm.get(j);
						break;
					}
					hm.put(j, cnt);
					j = ar[j];
					k--;
					cnt++;
				}
				if(k!=0)
				k = k % val;
				while (k > 0L) {
					j = ar[j];
					k--;
	
				}
				out.append(j);
			}
	
			System.out.println(out);
		}
	}
