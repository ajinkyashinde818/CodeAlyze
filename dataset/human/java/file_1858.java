import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;
import java.util.Collections;
import java.util.Arrays;
import java.lang.Math;

public class Main {
	public static void main(String[] args) {
		FS reader = new FS();
		// write reader
		int D = reader.nextInt();
		int G = reader.nextInt()/100;
		int[] P = new int[D];
		int[] C = new int[D];
		for(int i=0; i<D; i++) {
		    P[i] = reader.nextInt();
		    C[i] = reader.nextInt()/100;
		}
		
		solver(D, G, P, C);
	}
	
	public static void solver(int D, int G, int[] P, int[] C) {
		// write logic
		int ans = Integer.MAX_VALUE;
		for(int i=0; i<(int)Math.pow(2,D); i++) {
		    int tmpsum = 0;
		    int cntsum = 0;
		    for(int j=0; j<D; j++) {
		        if((i & (int)Math.pow(2,j)) > 0) {
		            tmpsum += (j+1)*P[j]+C[j];
		            cntsum += P[j];
		        }
		    }
		    if(G <= tmpsum) {
		        ans = Math.min(ans, cntsum);
		        continue;
		    }
		    int plusid = -1;
		    for(int j=D-1; j>=0; j--) {
		        if((i & (int)Math.pow(2,j)) == 0) {
		            plusid = j;
		            break;
		        }
		    }
		    int need = (int)Math.ceil((double)(G-tmpsum)/(double)(plusid+1));
		    if(need<P[plusid]) ans = Math.min(ans, cntsum+need);
		}
		System.out.println(ans);
	}
	
	// Read Class
	static class FS {
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
	
		private int readByte() { return hasNextByte() ? buffer[ptr++] : -1;}
		private boolean isPrintableChar(int c) {return 33 <= c && c <= 126;}
		private void skipUnprintable() {while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
	
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
		public int nextInt() {
			return (int)nextLong();
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
			while(true) {
				if ('0' <= b && b <= '9') {
					n *= 10;
					n += b - '0';
				} else if(b == -1 || !isPrintableChar(b)) {
					return minus ? -n : n;
				} else {
					throw new NumberFormatException();
				}
				b = readByte();
			}
		}
	}
}
