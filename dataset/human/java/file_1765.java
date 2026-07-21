import java.util.*;
import java.math.*;
public class Main{

	static int INF = 2 << 27;
	static int m;
	static int n;
	static int k;
	static int d;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			m = sc.nextInt();
			n = sc.nextInt();
			k = sc.nextInt();
			d = sc.nextInt();
			if(m == 0 && n == 0 && k == 0 && d == 0) break;
			int[] c = new int[m];
			for(int i = 0; i < m; i++) {
				c[i] = sc.nextInt();
			}
			Node[] node = new Node[m + n + 2];
			for(int i = 0; i < m; i++) {
				node[i] = new Node();
				node[i].type = 2;
			}
			for(int i = m; i < m + n; i++) {
				node[i] = new Node();
				node[i].type = 3;
			}
			node[m + n    ] = new Node();
			node[m + n    ].type = 0;
			node[m + n + 1] = new Node();
			node[m + n + 1].type = 1;
			
			for(int i = 0; i < d; i++) {
				String a = sc.next();
				String b = sc.next();
				int cost = sc.nextInt();
				int idA = -100;
				int idB = -100;
				if(a.length() == 1) {
					if(a.equals("H")) idA = m + n;
					else 			  idA = m + n + 1;
				}
				if(b.length() == 1) {
					if(b.equals("H")) idB = m + n;
					else			  idB = m + n + 1;
				}
				if(idA == -100) {
					if(a.charAt(0) == 'C') {
						idA = Integer.parseInt(a.substring(1)) - 1;
					}
					else {
						idA = m + Integer.parseInt(a.substring(1)) - 1;
					}
				}
				
				if(idB == -100) {
					if(b.charAt(0) == 'C') {
						idB = Integer.parseInt(b.substring(1)) - 1;
					}
					else {
						idB = m + Integer.parseInt(b.substring(1)) - 1;
					}
				}
				node[idA].edge_to.add(idB);
				node[idA].edge_cost.add(cost);
				node[idB].edge_to.add(idA);
				node[idB].edge_cost.add(cost);
			}
			int[][] dp = new int[n + m + 2][1 << m];
			for(int i = 0; i < dp.length; i++) {
				for(int j = 0; j < dp[i].length; j++) {
					dp[i][j] = INF;
				}
			}
			PriorityQueue<Data> queue = new PriorityQueue<Data>();
			queue.add(new Data(m + n,new boolean[m],0));
			while(!queue.isEmpty()) {
				Data tmp = queue.poll();
				int V = 0;
				for(int i = 0; i < tmp.v.length; i++) {
					if(tmp.v[i]) {
						V |= 1 << i;
					}
				}
				if(dp[tmp.now][V] <= tmp.cost) continue;
				dp[tmp.now][V] = tmp.cost;
				Node now = node[tmp.now];
				for(int i = 0; i < now.edge_to.size(); i++) {
					if(node[now.edge_to.get(i)].type == 2 && tmp.v[now.edge_to.get(i)]) continue;
					if(node[now.edge_to.get(i)].type == 2) {
						boolean[] copy = Arrays.copyOf(tmp.v, tmp.v.length);
						copy[now.edge_to.get(i)] = true; 
						queue.add(new Data(now.edge_to.get(i),copy, tmp.cost - c[now.edge_to.get(i)] + now.edge_cost.get(i) * k));
					}
					else {
						queue.add(new Data(now.edge_to.get(i),tmp.v, tmp.cost + now.edge_cost.get(i) * k));
					}
				}
			}
			int MIN = Integer.MAX_VALUE;
			for(int i = 0; i < dp[m + n + 1].length; i++) {
				MIN = Math.min(MIN, dp[m + n + 1][i]);
			}
			System.out.println(MIN);
		}
	}
	static class Data implements Comparable<Data>{
		int cost;
		boolean[] v;
		int now;
		@Override
		public int compareTo(Data o) {
			return this.cost - o.cost;
		}
		Data(int c, boolean[] b, int a) {
			cost = a;
			v    = b;
			now  = c;
		}
	}
	static class Node {
		int type; // 0 H, 1 D, 2 C, 3 L
		boolean c;
		ArrayList<Integer> edge_to = new ArrayList<Integer>();
		ArrayList<Integer> edge_cost = new ArrayList<Integer>();
	}
}
