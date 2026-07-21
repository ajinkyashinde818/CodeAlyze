import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;

public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int n = (int) sc.nextLong();
		long k = sc.nextLong();

		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = (int) (sc.nextLong()-1);
		}
		boolean[] visited = new boolean[n];
		visited[0] = true;
		List<Integer> set = new ArrayList<>(2*n);
		int pos = 0;
		int cycleStart = 0;
		int cycleEnd = n;
		set.add(0);
		for (int i = 0; i < n; i++) {
			
			if( visited[a[pos]]) {
				int index = set.indexOf(a[pos]);
				cycleStart = index;
				cycleEnd = i+1;
				break;
			}
			visited[a[pos]] = true;
			set.add(a[pos]);
			pos = a[pos];
		}
		
		int l = cycleEnd - cycleStart;
		long fixK = (k - cycleStart) % l + cycleStart;
		
		System.err.println( cycleStart);
		System.err.println( cycleEnd);
		System.err.println( fixK);
		System.err.println( set);
		if( k<cycleStart) {
			System.out.println( set.get((int)k) + 1);
		} else {
			k -= cycleStart;
			k %= l;
			k += cycleStart;
			System.out.println( set.get((int)k) + 1);
			
		}
		
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
    private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
    public boolean hasNext() { skipUnprintable(); return hasNextByte();}
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
}
