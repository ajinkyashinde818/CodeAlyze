import java.text.DecimalFormat;
import java.util.stream.LongStream;
import java.util.stream.IntStream;
import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        AtCoder problem = new AtCoder(sc);
        problem.solve(out);
        
        out.flush();
    }
    
}

class AtCoder {
    final int N;
    int[] A,B,C;
    AtCoder(FastScanner sc) {
        N = sc.nextInt();
        A = new int[N];
        B = new int[N];
        C = new int[N-1];
        A = IntStream.range(0, N).map(i -> sc.nextInt() -1).toArray();
        B = IntStream.range(0, N).map(i -> sc.nextInt()).toArray();
        C = IntStream.range(0, N-1).map(i -> sc.nextInt()).toArray();
    }

    void solve(PrintWriter out) {
        int prev_index = A[0];
        int sum = B[prev_index];
        for (int i = 1; i < N; i++) {
            int index = A[i];
            sum += B[index];
            if (prev_index == index - 1) {
                sum += C[prev_index];
            }
            prev_index = index;
        }
        out.println(sum);
    }
    
}

// https://qiita.com/p_shiki37/items/a0f6aac33bf60f5f65e4
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
        if (hasNextByte()) {
            return buffer[ptr++];
        } else {
            return -1;
        }
    }
    
    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }
    
    public boolean hasNext() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr])) {
            ptr++;
        }
        return hasNextByte();
    }
    
    public String next() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    public long nextLong() {
        if (!hasNext()) {
            throw new NoSuchElementException();
        }
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
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) {
            throw new NumberFormatException();
        }
        return (int) nl;
    }
    
    public double nextDouble() {
        return Double.parseDouble(next());
    }
}
