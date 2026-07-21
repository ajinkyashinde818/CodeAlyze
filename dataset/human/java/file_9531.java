import java.io.*;
import java.util.*;

public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
    
    long MAX = 100000L, MOD = 1000000007L, INF = (long) 1e18;
    
    void solve(int TC) throws Exception {
        int n = ni();
        int[][] a = new int[n][2];
        for(int i=0;i<n;i++) {
        	a[i][0] = ni();
        	a[i][1] = ni();
        }
        boolean ok = false;
        for(int i=1;i<n-1;++i) {
        	if(a[i-1][0] == a[i-1][1] && a[i][0] == a[i][1] && a[i+1][0] == a[i+1][1]) ok = true;
        }
        pn( ok ? "Yes" : "No");
    }
    
    boolean TestCases = false;
    public static void main(String[] args) throws Exception { new Main().run(); }
    
    void hold(boolean b)throws Exception{if(!b)throw new Exception("Hold right there, Sparky!");}
    static void dbg(Object... o){System.err.println(Arrays.deepToString(o));}
    
    long pow(long a, long b) {
        if(b==0 || a==1) return 1;
        long o = 1;
        for(long p = b; p > 0; p>>=1) {
            if((p&1)==1) o = (o*a) % MOD;
            a = (a*a) % MOD;
        } return o;
    }
    
    long inv(long x) {
        long o = 1;
        for(long p = MOD-2; p > 0; p>>=1) {
            if((p&1)==1)o = (o*x)%MOD;
            x = (x*x)%MOD;
        } return o;
    }
    long gcd(long a, long b) { return (b==0) ? a : gcd(b,a%b); }
    int gcd(int a, int b) { return (b==0) ? a : gcd(b,a%b); }
    
    void run() throws Exception {
        is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
        out = new PrintWriter(System.out);
        long s = System.currentTimeMillis();
        int T = TestCases ? ni() : 1;
        for(int t=1;t<=T;t++) solve(t);
        out.flush();
        if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
    }
    
    void p(Object o) { out.print(o); }
    void pn(Object o) { out.println(o); }
    void pni(Object o) { out.println(o);out.flush(); }
    double PI = 3.141592653589793238462643383279502884197169399;
    
    int ni() {
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-') {
            minus = true;
            b = readByte();
        }
        while(true) {
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-') {
            minus = true;
            b = readByte();
        }
        while(true) {
            if(b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    
    double nd() { return Double.parseDouble(ns()); }
    char nc() { return (char)skip(); }
    
    int BUF_SIZE = 1024 * 8;
    byte[] inbuf = new byte[BUF_SIZE];
    int lenbuf = 0, ptrbuf = 0;
    
    int readByte() {
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        } return inbuf[ptrbuf++];
    }
    
    boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
    int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
    
    String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(isSpaceChar(b))) {
            sb.appendCodePoint(b); b = readByte();
        } return sb.toString();
    }
    
    char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(isSpaceChar(b))){
            buf[p++] = (char)b;
            b = readByte();
        } return n == p ? buf : Arrays.copyOf(buf, p);
    }
    
    void tr(Object... o) { if(INPUT.length() > 0)System.out.println(Arrays.deepToString(o)); }
}
