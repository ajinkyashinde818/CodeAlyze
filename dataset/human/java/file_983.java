import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long mod = 1_000_000_007;
    long inf = Long.MAX_VALUE;

    void solve(){
        int n = ni();
        long c = nl();
        long[] x = new long[n];
        long[] v = new long[n];
        long[] d = new long[n];
        long[] b = new long[n];
        for(int i = 0; i < n; i++){
            x[i] = nl();
            v[i] = nl();
            d[i] = x[i]%c;
            b[i] = (c-x[i])%c;
        }
        long[][] dmax = new long[n][2];
        long[][] bmax = new long[n][2];
        long max = 0;
        long res = 0;
        long total = 0;
        int id = -1;
        for(int i = 0; i < n; i++){
            res += v[i];
            total = res - d[i];
            if(total>max){
                max = total;
                id = i;
            }
            dmax[i][0] = id;
            dmax[i][1] = max;
        }
        max = 0;
        res = 0;
        total = 0;
        id = -1;
        for(int i = 0; i < n; i++){
            res += v[n-1-i];
            total = res - b[n-1-i];
            if(total>max){
                max = total;
                id = i;
            }
            bmax[i][0] = id;
            bmax[i][1] = max;
        }
        max = 0;
        res = 0;
        total = 0;
        for(int i = 0; i < n; i++){
            max = Math.max(max, bmax[i][1]);
            max = Math.max(max, dmax[i][1]);
        }
        for(int i = 0; i < n; i++){
            res += v[i];
            total = res - 2*d[i];
            if(i<n-1)total += bmax[n-2-i][1];
            max = Math.max(max, total);
        }
        res = 0;
        total = 0;
        for(int i = 0; i < n; i++){
            res += v[n-1-i];
            total = res - 2*b[n-1-i];
            if(i<n-1)total += dmax[n-2-i][1];
            max = Math.max(max, total);
        }
        out.println(max);
    }

    void run() throws Exception
    {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        long s = System.currentTimeMillis();
        solve();
        out.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }
    
    public static void main(String[] args) throws Exception { new Main().run(); }
    
    private byte[] inbuf = new byte[1024];
    private int lenbuf = 0, ptrbuf = 0;
    
    private int readByte()
    {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
    
    private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
    
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
    
    private String ns()
    {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b) && b != ' ')){
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    
    private char[] ns(int n)
    {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    
    private char[][] nm(int n, int m)
    {
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
    
    private int[] na(int n)
    {
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
    
    private int ni()
    {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private long nl()
    {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
 
}
