import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        ConsoleIO io = new ConsoleIO(new InputStreamReader(System.in), new PrintWriter(System.out));

//        String fileName = "C-large";
//        ConsoleIO io = new ConsoleIO(new FileReader("D:\\Dropbox\\code\\practice\\jb\\src\\" + fileName + ".in"), new PrintWriter(new File("D:\\Dropbox\\code\\practice\\jb\\src\\" + fileName + ".out")));

        new Main(io).solve();
//        new Main(io).solveLocal();

        io.close();
    }

    ConsoleIO io;
    Main(ConsoleIO io) {
        this.io = io;
    }
    ConsoleIO opt;
    Main(ConsoleIO io, ConsoleIO opt) {
        this.io = io; this.opt = opt;
    }

    List<List<Integer>> gr = new ArrayList<>();
    long MOD = 1_000_000_007;

    public void solve() {
        int n = io.ri();
        long C = io.readLong();
        Sushi[] all = new Sushi[n];
        long sum = 0;
        for(int i = 0;i<n;i++){
            long d = io.readLong();
            long v = io.readLong();
            all[i] = new Sushi(d,v);
            sum+=v;
        }
        Arrays.sort(all, (s1,s2)->Long.compare(s1.dist, s2.dist));
        long[] best1 = new long[n];
        long[] bestBack1 = new long[n];
        long[] best2 = new long[n];
        long[] bestBack2 = new long[n];
        best1[0] = Math.max(0, all[0].val-all[0].dist);
        bestBack1[0] = Math.max(0, all[0].val-2*all[0].dist);
        best2[n-1] = Math.max(0, all[n-1].val-(C-all[n-1].dist));
        bestBack2[n-1] = Math.max(0, all[n-1].val-2*(C-all[n-1].dist));
        long cur = all[0].val;
        for(int i = 1;i<n;i++){
            Sushi s = all[i];
            cur+=s.val;
            best1[i] = Math.max(best1[i-1], cur-s.dist);
            bestBack1[i] = Math.max(bestBack1[i-1], cur-2*s.dist);
        }
        cur = all[n-1].val;
        for(int i = n-2;i>=0;i--){
            Sushi s = all[i];
            cur+=s.val;
            long d = C - s.dist;
            best2[i] = Math.max(best2[i+1], cur-d);
            bestBack2[i] = Math.max(bestBack2[i+1], cur-2*d);
        }
        long res = Math.max(best1[n-1], best2[0]);
        for(int i = 1;i<n;i++){
            long v = Math.max(best1[i-1] + bestBack2[i], bestBack1[i-1] + best2[i]);
            res = Math.max(res, v);
        }

        io.writeLine(res+"");
    }

    class Sushi{
        public Sushi(long d, long v){
            dist = d;
            val = v;
        }
        long dist;
        long val;
    }
}

class ConsoleIO {

    BufferedReader br;
    PrintWriter out;
    public ConsoleIO(Reader reader, PrintWriter writer){br = new BufferedReader(reader);out = writer;}
    public void flush(){this.out.flush();}
    public void close(){this.out.close();}
    public void writeLine(String s) {this.out.println(s);}
    public void writeInt(int a) {this.out.print(a);this.out.print(' ');}
    public void writeWord(String s){
        this.out.print(s);
    }
    public void writeIntArray(int[] a, int k, String separator) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < k; i++) {
            if (i > 0) sb.append(separator);
            sb.append(a[i]);
        }
        this.writeLine(sb.toString());
    }
    public int read(char[] buf, int len){try {return br.read(buf,0,len);}catch (Exception ex){ return -1; }}
    public String readLine() {try {return br.readLine();}catch (Exception ex){ return "";}}
    public long[] readLongArray() {
        String[]n=this.readLine().trim().split("\\s+");long[]r=new long[n.length];
        for(int i=0;i<n.length;i++)r[i]=Long.parseLong(n[i]);
        return r;
    }
    public int[] readIntArray() {
        String[]n=this.readLine().trim().split("\\s+");int[]r=new int[n.length];
        for(int i=0;i<n.length;i++)r[i]=Integer.parseInt(n[i]);
        return r;
    }
    public int[] readIntArray(int n) {
        int[] res = new int[n];
        char[] all = this.readLine().toCharArray();
        int cur = 0;boolean have = false;
        int k = 0;
        boolean neg = false;
        for(int i = 0;i<all.length;i++){
            if(all[i]>='0' && all[i]<='9'){
                cur = cur*10+all[i]-'0';
                have = true;
            }else if(all[i]=='-') {
                neg = true;
            }
            else if(have){
                res[k++] = neg?-cur:cur;
                cur = 0;
                have = false;
                neg = false;
            }
        }
        if(have)res[k++] = neg?-cur:cur;
        return res;
    }
    public int ri() {
        try {
            int r = 0;
            boolean start = false;
            boolean neg = false;
            while (true) {
                int c = br.read();
                if (c >= '0' && c <= '9') {
                    r = r * 10 + c - '0';
                    start = true;
                } else if (!start && c == '-') {
                    start = true;
                    neg = true;
                } else if (start || c == -1) return neg ? -r : r;
            }
        } catch (Exception ex) {
            return -1;
        }
    }
    public long readLong() {
        try {
            long r = 0;
            boolean start = false;
            boolean neg = false;
            while (true) {
                int c = br.read();
                if (c >= '0' && c <= '9') {
                    r = r * 10 + c - '0';
                    start = true;
                } else if (!start && c == '-') {
                    start = true;
                    neg = true;
                } else if (start || c == -1) return neg ? -r : r;
            }
        } catch (Exception ex) {
            return -1;
        }
    }
    public String readWord() {
        try {
            boolean start = false;
            StringBuilder sb = new StringBuilder();
            while (true) {
                int c = br.read();
                if (c!= ' ' && c!= '\r' && c!='\n' && c!='\t') {
                    sb.append((char)c);
                    start = true;
                } else if (start || c == -1) return sb.toString();
            }
        } catch (Exception ex) {
            return "";
        }
    }
    public char readSymbol() {
        try {
            while (true) {
                int c = br.read();
                if (c != ' ' && c != '\r' && c != '\n' && c != '\t') {
                    return (char) c;
                }
            }
        } catch (Exception ex) {
            return 0;
        }
    }
//public char readChar(){try {return (char)br.read();}catch (Exception ex){ return 0; }}
}
class Pair {
    public Pair(int a, int b) {this.a = a;this.b = b;}
    public int a;
    public int b;
}
class PairLL {
    public PairLL(long a, long b) {this.a = a;this.b = b;}
    public long a;
    public long b;
}
class Triple {
    public Triple(int a, int b, int c) {this.a = a;this.b = b;this.c = c;}
    public int a;
    public int b;
    public int c;
}
