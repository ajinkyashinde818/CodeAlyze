import java.io.*;
import java.util.*;
import java.math.*;
// import java.awt.Point;
 
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
 
    long MOD = 1_000_000_007;
    int inf = Integer.MAX_VALUE;

    void solve(){
        char[] s = ns().toCharArray();
        int n = s.length;
        int x = ni();
        int y = ni();
        int m = 20000;
        boolean[] dpx = new boolean[2*m+1];
        boolean[] dpy = new boolean[2*m+1];
        int res = 0;
        int dir = 0;
        dpx[m] = true;
        for(int i = 0; i < n; i++){
            boolean[] ndpx = new boolean[2*m+1];
            if(s[i]=='F'){
                res++;
            }
            if((s[i]=='T'||i==n-1)&&res>0){
                if(dir%2==0){
                   for(int j = -n; j <= n; j++){
                        if(dir>0) ndpx[j-res+m] |= dpx[j+m];
                        ndpx[j+res+m] |= dpx[j+m];
                   } 
                   dpx = ndpx;
               }
            }
            if(s[i]=='T'){
                dir++;
                res = 0;
            }
        }
        dir = 0;
        dpy[m] = true;
        for(int i = 0; i < n; i++){
            boolean[] ndpy = new boolean[2*m+1];
            if(s[i]=='F'){
                res++;
            }
            if((s[i]=='T'||i==n-1)&&res>0){
                if(dir%2==1){
                   for(int j = -n; j <= n; j++){
                        ndpy[j-res+m] |= dpy[j+m];
                        ndpy[j+res+m] |= dpy[j+m];
                   } 
                   dpy = ndpy;
               }
            }
            if(s[i]=='T'){
                dir++;
                res = 0;
            }
        }
        if(dpx[x+m] && dpy[y+m]){
            out.println("Yes");
        }
        else out.println("No");
        // for(int i = -n; i <= n; i++){
        //     if(dpx[i+m]>0) out.println(i);
        // }
        // for(int i = -n; i <= n; i++){
        //     if(dpy[i+m]>0) out.println(i);
        // }

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
