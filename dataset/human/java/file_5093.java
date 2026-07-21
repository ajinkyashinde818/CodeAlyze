import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
 
public class Main implements Runnable {
    public static void main(String[] args) {
        new Thread(null,new Main(), "" ,Runtime.getRuntime().maxMemory()).start();
    }
 
    public void run() {
        FastScanner sc = new FastScanner();
        String s = sc.next();
        int q = sc.nextInt();
        StringBuilder sb = new StringBuilder(s);
        StringBuilder left = new StringBuilder();
        StringBuilder right = new StringBuilder();
        boolean reverse = false;
        for(int i = 0;i < q;i++) {
            int query = sc.nextInt();
            if(query == 1) reverse = !reverse;
            else {
                int f = sc.nextInt();
                char c = sc.next().toCharArray()[0];
                if(reverse) f = (f == 1 ? 2 : 1);
                if(f == 1) left.append(c);
                else right.append(c);
            }
        }
        left.reverse().append(sb.toString()).append(right.toString());
        if(reverse) left.reverse();
        
        PrintWriter out =  new PrintWriter(System.out);
        out.println(left.toString());
        out.flush();
    }
 
    long nCm(int n, int m) {
        if(n < m) return 0l;
        long c = 1;
        m = (n - m < m ? n - m : m);
        for(int ns = n - m + 1, ms = 1;ms <= m;ns ++, ms++) {
            c *= ns;
            c /= ms;
        }
        return c;
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
