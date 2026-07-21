import java.io.File;
import java.io.FileInputStream;
import java.util.Scanner;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.NoSuchElementException;

public class Main {
	
	public static void main(String[] args) throws IOException {
		FastScanner sc = new FastScanner(System.in);
		PrintWriter out = new PrintWriter(System.out);;
		
		int N = sc.nextInt();
		UnionFind road = new UnionFind(N);
		UnionFind train = new UnionFind(N);
		int K = sc.nextInt();
		int L = sc.nextInt();
		for(int i = 0; i < K; i++){
			int p = sc.nextInt() - 1;
			int q = sc.nextInt() - 1;
			road.unite(p, q);
		}
		for(int i = 0; i < L; i++){
			int r = sc.nextInt() - 1;
			int s = sc.nextInt() - 1;
			train.unite(r, s);
		}
		
		HashMap<Long, Integer> map = new HashMap<Long, Integer>();
		
		for(int i = 0; i < N; i++){
			long k = (long)road.find(i) * N + train.find(i);
			Integer count = map.get(k);
			if(count == null) map.put(k, 1);
			else map.put(k, count+1);
		}
		
		StringBuilder ans = new StringBuilder();
		for(int i = 0; i < N; i++){
			long k = (long)road.find(i) * N + train.find(i);
			ans.append(map.get(k));
			if(i == N - 1) ans.append("\n");
			else ans.append(" ");
		}
		out.print(ans);
		out.flush();
	}
}

class UnionFind{
	int[] par;
	int[] rank;
	int group;
	UnionFind(int n){
		par = new int[n];
		rank = new int[n];
		group = n;
		for(int i = 0; i < n; i++){
			par[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x){
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		group--;
		if(rank[x] > rank[y]) par[x] = y;
		else{
			par[y] = x;
			if(rank[x] == rank[y]) rank[x]++;
		}
	}
	boolean same(int x, int y){
		return find(x) == find(y);
	}
}

class FastScanner {
    private InputStream in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    public FastScanner(InputStream in) {
		this.in = in;
	}
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
    private int readByte() {
    	if (hasNextByte()) return buffer[ptr++];
    	else return -1;
    }
    private static boolean isPrintableChar(int c){
    	return 33 <= c && c <= 126;
    }
    public boolean hasNext() {
    	while(hasNextByte() && !isPrintableChar(buffer[ptr]))
    		ptr++; return hasNextByte();
    }
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
    public double nextDouble() {
    	return Double.parseDouble(next());
    }
}
