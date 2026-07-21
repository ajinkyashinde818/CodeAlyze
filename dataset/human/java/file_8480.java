import java.util.*;
import java.io.*;

class UnionFind{
	int parent[];
	UnionFind(int n){
		parent = new int[n];
		Arrays.fill(parent,-1);
	}
	
	int root(int x) {
		if(parent[x]<0)return x;
		return parent[x] = root(parent[x]);
	}
	
	boolean same(int x, int y) {
		return root(x) == root(y);
	}
	
	int size(int x) {
		return -parent[root(x)];
	}
	
	void unite(int x, int y) {
		if(same(x, y))return;
		if(size(x)>size(y)){
			int tmp = x;
			x = y;
			y = tmp;
		}
		parent[root(y)] += parent[root(x)];
		parent[root(x)] = root(y);
	}
	
}

class Pair{
	int troot, croot;
	public Pair(int troot, int croot) {
		super();
		this.troot = troot;
		this.croot = croot;
	}
	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + croot;
		result = prime * result + troot;
		return result;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Pair other = (Pair) obj;
		if (croot != other.croot)
			return false;
		if (troot != other.troot)
			return false;
		return true;
	}
	
	
	
}

public class Main {
	static int mod = (int) 1e9 + 7;
	static int DX[] = { -1, 0, 1, 0 }, DY[] = { 0, -1, 0, 1 };
	static final int INF = Integer.MAX_VALUE / 3;
	static final long LINF = Long.MAX_VALUE / 3;

	public static void main(String[] args) {
		FastScanner fs = new FastScanner(System.in);
		int n = fs.nextInt(), k = fs.nextInt(), l = fs.nextInt();
		UnionFind uft = new UnionFind(n);
		UnionFind ufc = new UnionFind(n);
		
		//電車でいけるグループ
		for(int i=0;i<k;i++) {
			int p = fs.nextInt()-1, q = fs.nextInt()-1;
			uft.unite(p, q);
		}
		//車でいけるグループ
		for(int i=0;i<l;i++) {
			int p = fs.nextInt()-1, q = fs.nextInt()-1;
			ufc.unite(p, q);
		}
		
		HashMap<Pair,Integer> map = new HashMap<>();
		for(int i=0;i<n;i++) {
			Pair pair = new Pair(uft.root(i), ufc.root(i));
			map.put(pair, map.getOrDefault(pair, 0)+1);
		}
		
		for(int i=0;i<n;i++) {
			Pair pair = new Pair(uft.root(i), ufc.root(i));			
			System.out.print(map.get(pair) + " ");
		}
		System.out.println();
		
	}

	//MOD culculations
	static long plus(long x, long y) {
		long res = (x + y) % mod;
		return res < 0 ? res + mod : res;
	}

	static long sub(long x, long y) {
		long res = (x - y) % mod;
		return res < 0 ? res + mod : res;
	}

	static long mul(long x, long y) {
		long res = (x * y) % mod;
		return res < 0 ? res + mod : res;
	}

	static long div(long x, long y) {
		long res = x * pow(y, mod - 2) % mod;
		return res < 0 ? res + mod : res;
	}

	static long pow(long x, long y) {
		if (y < 0)
			return 0;
		if (y == 0)
			return 1;
		if (y % 2 == 1)
			return (x * pow(x, y - 1)) % mod;
		long root = pow(x, y / 2);
		return root * root % mod;
	}
}

//高速なScanner
class FastScanner {
	private BufferedReader reader = null;
	private StringTokenizer tokenizer = null;

	public FastScanner(InputStream in) {
		reader = new BufferedReader(new InputStreamReader(in));
		tokenizer = null;
	}

	public String next() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}

	public String nextLine() {
		if (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				return reader.readLine();
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken("\n");
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public int[] nextIntArray(int n) {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = nextInt();
		return a;
	}

	public long[] nextLongArray(int n) {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = nextLong();
		return a;
	}
}
