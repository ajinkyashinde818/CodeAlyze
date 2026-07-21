import java.io.*;
import java.util.*;

public class Main {
    public static final long mod = (long)1e9+7;
    public static final long INF = Long.MAX_VALUE/2;
    public static final int inf = Integer.MAX_VALUE/2;

    public static int[] arr;
    static void solve(InputReader in, PrintWriter out){
        int d = in.ni(), g = in.ni();
        int[] p = new int[d], c = new int[d];
        int min = inf;
        arr = new int[d];
        for (int i = 0; i < d; i++) arr[i] = i+1;
        for (int i = 0; i < d; i++) {
            p[i] = in.ni();
            c[i] = in.ni();
        }
        boolean flag = true;
        while(flag){
            int a = g;
            int count = 0;
            for (int i = 0; i < d; i++) {
                int num = (a+100*arr[i]-1)/(100*arr[i]);
                if(num >= p[arr[i]-1]){
                    count += p[arr[i]-1];
                    a -= (c[arr[i]-1]+arr[i]*100*p[arr[i]-1]);
                }else{
                    count += num;
                    a -= arr[i]*100*num;
                }
                if(a <= 0) break;
            }
            min = Math.min(min, count);
            flag = nextPermutation(arr);
        }
        out.println(min);
    }
    public static boolean nextPermutation(int[] a) {
        for (int i = a.length - 1; i > 0; --i) {
            if (a[i - 1] < a[i]) {
                int swapIndex = find(a[i - 1], a, i, a.length - 1);
                int temp = a[swapIndex];
                a[swapIndex] = a[i - 1];
                a[i - 1] = temp;
                Arrays.sort(a, i, a.length);
                return true;
            }
        }
        return false;
    }
    public static int find(int dest, int[] a, int s, int e) {
        if (s == e) return s;
        int m = (s + e + 1) / 2;
        return a[m] <= dest ? find(dest, a, s, m - 1) : find(dest, a, m, e);
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
