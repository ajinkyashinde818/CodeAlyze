import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		int k = sc.nextInt();
		int l = sc.nextInt();
		UnionFind uf1 = new UnionFind(n);
		for(int i = 0; i < k; i++){
		    int p = sc.nextInt()-1;
		    int q = sc.nextInt()-1;
		    uf1.union(p, q);
		}
		UnionFind uf2 = new UnionFind(n);
		for(int i = 0; i < l; i++){
		    int p = sc.nextInt()-1;
		    int q = sc.nextInt()-1;
		    uf2.union(p, q);
		}
		
		// 計算
		long result = 0;
		HashMap<Long, Integer> hm = new HashMap<Long, Integer>();
		Long[] keys = new Long[n];
		for(int i = 0; i < n; i++){
		    long key = uf1.find(i)*(long)n + uf2.find(i);
		    keys[i] = key;
		    hm.put(keys[i], hm.getOrDefault(keys[i], 0)+1);
		}
		
		// 出力
		for(int i = 0; i < n; i++){
		    System.out.print(hm.get(keys[i]));
		    System.out.print(" ");
		}
		//System.out.println(result);
	}
	
	public static class Scanner {
		private BufferedReader br; private StringTokenizer tok;
		public Scanner(InputStream is) throws IOException { br = new BufferedReader(new InputStreamReader(is));}
		private void getLine() throws IOException { while(!hasNext()) tok = new StringTokenizer(br.readLine());}
		private boolean hasNext() { return tok != null && tok.hasMoreTokens();}
		public String next() throws IOException { getLine(); return tok.nextToken();}
		public int nextInt() throws IOException { return Integer.parseInt(next());}
		public long nextLong() throws IOException { return Long.parseLong(next());}
		public double nextDouble() throws IOException { return Double.parseDouble(next());}
	}
}

class UnionFind {
	int[] parent;
	int[] rank;
	int[] cnt;
	
	UnionFind(int n){
		this.parent = new int[n];
		this.rank = new int[n];
		this.cnt = new int[n];
		for(int i = 0; i < n; i++){
			parent[i] = i;
			rank[i] = 0;
			cnt[i] = 1;
		}
	}
	
	public int find(int i){
		if(i == parent[i]) return i;
		parent[i] = find(parent[i]);
		return parent[i];
	}
	
	public boolean union(int x, int y){
		int xRoot = find(x);
		int yRoot = find(y);
		if(xRoot == yRoot) return false;
		if(rank[xRoot] < rank[yRoot]){
			parent[xRoot] = yRoot;
			cnt[yRoot] += cnt[xRoot];
		}else if(rank[xRoot] > rank[yRoot]){
			parent[yRoot] = xRoot;
			cnt[xRoot] += cnt[yRoot];
		}else{
			parent[yRoot] = xRoot;
			rank[xRoot]++;
			cnt[xRoot] += cnt[yRoot];
		}
		return true;
	}
	
	public boolean same(int x, int y){
		return find(x) == find(y);
	}

	public int cnt(int x){
		return cnt[find(x)];
	}
}
