import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int[] A = new int[] {4,1,4,1,2,1,2,1};
		int[] list = new int[8];
		int[] ANS = new int[8];
		while(sc.hasNext()) {
			for(int i = 0; i < 8; i++) {
				list[i] = sc.nextInt();
			}
			int max = Integer.MAX_VALUE;
			int V = 99999999;
			for(int i = 0; i < 8; i++) {
				int sum = 0;
				for(int j = 0; j < 8; j++) {
					sum += Math.max(0, list[j] - A[j]);
				}
				if(max > sum) {
					max = sum;
					ANS = Arrays.copyOf(A, A.length);
				}
				else if(max == sum && K(A) < K(ANS)) {
					ANS = Arrays.copyOf(A, A.length);
				}
				R(A);
			}
			out.print(ANS[0]);
			for(int i = 1; i < 8; i++) {
				out.print(" " + ANS[i]);
			}
			out.println();
			
		}
		out.flush();

	}
	static void R(int[] a) {
		int tmp = a[7];
		for(int i = 7; i >= 1; i--) {
			a[i] = a[i-1];
		}
		a[0] = tmp;
	}
	
	static int K(int[] a) {
		int ret = 0;
		for(int i = 0; i < 8; i++) {
			ret += a[i] * Math.pow(10, 8-i);
		}
		return ret;
	}
}
//------------------------------//
//-----------//
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
    
    public int nextInt() {
    	return (int)nextLong();
    }
    

}
