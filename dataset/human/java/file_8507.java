import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int k=sc.nextInt();
		int l=sc.nextInt();
		DSet ds1 = new DSet(n+1);
		DSet ds2 = new DSet(n+1);
		for(int i=0; i<k; i++) {
			ds1.unite(sc.nextInt(), sc.nextInt());
		}
		for(int i=0; i<l; i++) {
			ds2.unite(sc.nextInt(), sc.nextInt());
		}
		HashMap<Long, Integer> m = new HashMap<>();
		for(int i=1; i<=n; i++) {
			long key = (long)ds1.findSet(i) * (long)n + (long)ds2.findSet(i);
			m.put(key, m.containsKey(key) ? m.get(key)+1 : 1);
		}
		for(int i=1; i<=n; i++) {
			if(i>1)System.out.print(" ");
			long key = (long)ds1.findSet(i) * (long)n + (long)ds2.findSet(i);
			System.out.print(m.get(key));
		}
		System.out.println();
		sc.close();
	}

	class DSet{

		int p[];
		int rank[];
		public DSet(int n) {
			p=new int[n];
			rank=new int[n];
			for(int i=0; i<n; i++) {
				makeSet(i);
			}
		}
		public void makeSet(int x) {
			p[x]=x;
			rank[x]=0;
		}

		public boolean same(int x, int y) {
			return findSet(x) == findSet(y);
		}

		public int findSet(int x) {
			if(p[x]!=x) {
				p[x]=findSet(p[x]);
			}
			return p[x];
		}

		public void link(int x, int y) {
			if(rank[x] < rank[y]) {
				p[x]=y;
			}else {
				p[y]=x;
				if(rank[x]==rank[y]) {
					rank[x]++;
				}
			}
		}
		public void unite(int x, int y) {
			link(findSet(x), findSet(y));
		}
	}
}
