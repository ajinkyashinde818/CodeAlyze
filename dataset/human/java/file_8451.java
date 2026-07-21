import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Map;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String args[]) {
		FastScanner scanner = new FastScanner();
		int n=scanner.nextInt();
		int k=scanner.nextInt();
		int l=scanner.nextInt();
		UnionFind uf1=new UnionFind(n);
		UnionFind uf2=new UnionFind(n);
		for(int i=0;i<k;i++) {
			int p=scanner.nextInt()-1;
			int q=scanner.nextInt()-1;
			uf1.union(p, q);
		}
		for(int i=0;i<l;i++) {
			int r=scanner.nextInt()-1;
			int s=scanner.nextInt()-1;
			uf2.union(r, s);
		}
		Map<Point,Integer>map=new HashMap<>();
		for(int i=0;i<n;i++) {
			int a=uf1.root(i);
			int b=uf2.root(i);
			Point key=new Point(a,b);
			if (map.containsKey(key)) {
				map.put(key, map.get(key) + 1);
			} else {
				map.put(key, 1);
			}
		}
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<n;i++) {
			int a=uf1.root(i);
			int b=uf2.root(i);
			Point key=new Point(a,b);
			sb.append(map.get(key)+" ");
		}
		System.out.println(sb);
	}
}

class Point {
	int x, y;

	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + x;
		result = prime * result + y;
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
		Point other = (Point) obj;
		if (x != other.x)
			return false;
		if (y != other.y)
			return false;
		return true;
	}
}

class UnionFind {
	int parent[];
	int rank[];

	public UnionFind(int n) {
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}

	public boolean same(int x, int y) {
		return root(x) == root(y);
	}

	public int root(int x) {
		if (parent[x] == x) {
			return x;
		} else {
			return parent[x] = root(parent[x]);
		}
	}

	public void union(int x, int y) {
		x = root(x);
		y = root(y);
		if (x != y) {
			if (rank[x] > rank[y]) {
				parent[y] = x;
			} else {
				parent[x] = y;
				if (rank[x] == rank[y]) {
					rank[y]++;
				}
			}
		}
		return;
	}

	public int count(int n) {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			if (i == root(i)) {
				ret++;
			}
		}
		return ret;
	}

}

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}
