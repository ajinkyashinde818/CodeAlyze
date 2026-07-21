import java.io.*;
import java.util.*;

public class Main {
    public static final long mod = (long)1e9+7;
    public static final long INF = Long.MAX_VALUE/2;
    public static final int inf = Integer.MAX_VALUE/2;
    
    static void solve(InputReader in, PrintWriter out){
        int n = in.ni(), m = in.ni();
        boolean[] from1 = new boolean[n];
        boolean[] toN = new boolean[n];
        for (int i = 0; i < m; i++) {
            int from = in.ni()-1, to = in.ni()-1;
            if(from == 0){
                from1[to] = true;
            }else if(to == 0){
                from1[from] = true;
            }
            if(from == n-1){
                toN[to] = true;
            }else if(to == n-1){
                toN[from] = true;
            }
        }
        boolean flag = false;
        for (int i = 1; i < n-1; i++) {
            if(from1[i]&&toN[i]) {
                flag= true;
                break;
            }
        }
        out.println(flag?"POSSIBLE":"IMPOSSIBLE");
    }

    public static void main(String[] args){
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        solve(in, out);
        out.close();
    }
    public static class InputReader{
        private BufferedReader br;
        private StringTokenizer st;
        public InputReader(InputStream is){
            br = new BufferedReader(new InputStreamReader(is));
            st = null;
        }
        public String ns(){
            if(st == null || !st.hasMoreTokens()){
                try{
                    st = new StringTokenizer(br.readLine());
                }catch (Exception e){
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }
        public int ni(){
            return Integer.parseInt(ns());
        }
        public long nl(){
            return Long.parseLong(ns());
        }
        public double nd(){
            return Double.parseDouble(ns());
        }
        public char nc(){
            return ns().toCharArray()[0];
        }
        public int[] ni(int n){
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }
        public long[] nl(int n){
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nl();
            }
            return a;
        }
        public double[] nd(int n){
            double[] a = new double[n];
            for (int i = 0; i < n; i++) {
                a[i] = nd();
            }
            return a;
        }
    }
}
