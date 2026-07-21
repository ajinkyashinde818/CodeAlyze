import java.util.*;
import static java.lang.System.*;
import java.io.*;
import java.math.*;

public class Main {
	static int n, m;
	static char[][] imageN, imageM;
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		n = sc.nextInt();
		m = sc.nextInt();
		imageN = new char[n][n];
		for(int i = 0; i < n; i++)
			imageN[i] = sc.next().toCharArray();
		imageM = new char[m][m];
		for(int i = 0; i < m; i++)
			imageM[i] = sc.next().toCharArray();
			
		boolean flag = false;
		for(int i = 0; i < n - m + 1; i++) {
			for(int j = 0; j < n - m + 1; j++) {
				flag = func(i, j);
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) out.println("Yes");
		else out.println("No");
		out.close();
	}
	//同一性判定。引数は始点（左上）の座標
	static boolean func(int y, int x) {
		boolean flag = true;
		for(int i = y; i < y + m; i++) {
			for(int j = x; j < x + m; j++) {
				if (imageN[i][j] != imageM[i - y][j - x]) {
					flag = false;
					break;
				}
			}
			if(!flag) break;
		}
		return flag;
	}

static class FastScanner {
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
}
