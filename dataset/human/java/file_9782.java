import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

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

public class Main {
	static int[][] books;
	static int N, M, X;

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ


		FastScanner fs = new FastScanner();
		N  = fs.nextInt();
		M  = fs.nextInt();
		X  = fs.nextInt();
		books = new int[N+1][M+1];
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j <= M; j++) {
				books[i][j] = fs.nextInt();
 			}
		}
		int min = Integer.MAX_VALUE;
		int[] new_rikaido = new int[M+1];
		for(int i = 1; i <= N; i++) {
			int a = getPrice(new_rikaido, i);
			if(a > 0) min = Math.min(min,a);
		}
		if(min ==  Integer.MAX_VALUE) {
			min = -1;
		}

		System.out.println(min);


	}

	static int getPrice(int[] rikaido, int index) {
		int[] new_rikaido = new int[M+1];

		for(int i = 1; i <= M; i++) {
			new_rikaido[i] = rikaido[i];
		}
		for(int i = 1; i <= M; i++) {
			new_rikaido[i] += books[index][i];
		}

		int count = 0;
		for(int i = 1; i <= M; i++) {
			if(new_rikaido[i] < X) count++;
		}
		if(count == 0) return books[index][0];

		if( index == N) return -1;

		int min = Integer.MAX_VALUE;
		for( int i = index + 1; i <= N; i++ ) {
			int a = getPrice(new_rikaido, i);
			if(a > 0) min = Math.min(min, a);

		}
		if(min ==  Integer.MAX_VALUE) {
			return -1;
		}
		return books[index][0] + min;




	}

}
