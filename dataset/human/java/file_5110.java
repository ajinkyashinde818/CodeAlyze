import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		FastScanner scan = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		String s = scan.next();
		int q = scan.nextInt();

		int i,t,f;
		int rc = 0;
		StringBuilder head = new StringBuilder();
		StringBuilder tail = new StringBuilder();

		for(i = 0; i < q; i++) {
			t = scan.nextInt();
			if(t == 1) {
				rc++;
			}else{
				f = scan.nextInt();
				if((f + rc) % 2 == 0) {
					tail.append(scan.next());
				}else {
					head.append(scan.next());
				}
			}
		}

		StringBuilder ans = new StringBuilder();
		if(rc % 2 == 1)
			ans.append(tail.reverse()).append(new StringBuilder(s).reverse()).append(head);
		else
			ans.append(head.reverse()).append(s).append(tail);

		out.println(ans.toString());
		out.close();
	}

}
class unionFind{
	int[] par;
	int[] size;

	unionFind(int x){
		this.par = new int[x + 1];
		this.size = new int[x + 1];

		int i;
		for(i = 0; i <= x; i++)
			this.par[i] = i;
		Arrays.fill(this.size, 1);
	}

	int root(int x) {
		int r = x;
		while (r != this.par[r]) {
	        r = this.par[r];
	      }

		return r;
	}

	void union(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if(rx == ry)
			return;

		if(this.size[rx] < this.size[ry]) {
			this.size[ry] += this.size[rx];
			this.par[rx] = ry;
		}else {
			this.size[rx] += this.size[ry];
			this.par[ry] = rx;
		}
	}

	int size(int x) {
		return this.size[root(x)];
	}

	boolean same(int x, int y) {
		int rx = root(x);
		int ry = root(y);

		return rx == ry;
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
