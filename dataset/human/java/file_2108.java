import java.io.*;
import java.util.*;

public class Main {
    public static final long mod = (long)1e9+7;
    public static final long INF = Long.MAX_VALUE/2;
    public static final int inf = Integer.MAX_VALUE/2;

    static void solve(InputReader in, PrintWriter out){
        long n = in.nl();
        long ans = 0;
        TreeMap<Long, Integer> fact = PrimeFactorization(n);
        for(Long prime: fact.keySet()){
            int e = fact.get(prime);
            int i = 1;
            while(i*(i+1)<=2*e) i++;
            i--;
            ans += i;
        }
        out.println(ans);
    }
    public static TreeMap<Long, Integer> PrimeFactorization(long n){
        TreeMap<Long, Integer> map = new TreeMap<>();
        long N = n;
        for (long i = 2; i*i <= N; i++) {
            while(n%i==0){
                map.put(i, map.containsKey(i)?map.get(i)+1:1);
                n /= i;
            }
        }
        if(n!=1) map.put(n, 1);
        return map;
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
