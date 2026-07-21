import java.io.*;
import java.util.*;

public class Main {
    public static final long mod = (long)1e9+7;
    public static final long INF = Long.MAX_VALUE/10;
    public static final int inf = Integer.MAX_VALUE/10;

    static void solve(InputReader in, PrintWriter out){
        int n = in.ni(), m = in.ni();
        char[][] a = new char[n][n];
        char[][] b = new char[m][m];
        for (int i = 0; i < n; i++) {
            a[i] = in.ns().toCharArray();
        }
        for (int i = 0; i < m; i++) {
            b[i] = in.ns().toCharArray();
        }
        boolean flag = true;
        out:for (int i = 0; i < n - m + 1; i++) {
            in:for (int j = 0; j < n - m + 1; j++) {
                flag = true;
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < m; l++) {
                        if(a[i+k][j+l]!=b[k][l]){
                            flag = false;
                            continue in;
                        }
                    }
                }
                if(flag) break out;
            }
        }
        out.println(flag?"Yes":"No");
    }

    public static void main(String[] args) throws Exception{
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
        public long nl(){
            return Long.parseLong(ns());
        }
        public int ni(){
            return Integer.parseInt(ns());
        }
        public Double nd(){
            return Double.parseDouble(ns());
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
