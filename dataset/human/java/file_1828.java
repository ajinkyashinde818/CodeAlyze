import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int D = sc.nextInt();
		int G = sc.nextInt() / 100;
		int[] p = new int[D];
		int[] c = new int[D];
		for (int i = 0; i < D; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt() / 100;
		}
		int[] comp = new int[D];
		for (int i = 0; i < D; i++) {
			comp[i] = (i+1) *  p[i] + c[i];
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < 2<<(D-1); i++) {
			String bit = Integer.toBinaryString(i);
			int num = 0;
			int point = 0;
			int h = D;
			boolean lock = false;
			for (int j = 0; j < bit.length(); j++) {
				if (bit.charAt(bit.length() -1 - j) == '1' ) {
					point += comp[D-1-j];
					num += p[D-1-j];
					if (!lock) h--;
				} else {
					lock = true;
				}
			}
			if (point >= G) {

			} else if (point < G && point + h*(p[h-1]-1) >= G) {
				num += (G-point + h - 1) / h;
			} else {
				continue;
			}
			ans = Math.min(ans, num);
		}
		System.out.println(ans);
	}



	public static long gcd(long a, long b) {
		long remainder = a % b;
		if (remainder == 0) {
			return b;
		} else {
			return gcd(b, remainder);
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
        } else {
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
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr]))
            ptr++;
        return hasNextByte();
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext())
            throw new NoSuchElementException();
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
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }

    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
            throw new NumberFormatException();
        return (int) nl;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }
}
