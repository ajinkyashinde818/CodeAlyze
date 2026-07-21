import java.io.*;
import java.util.*;

public class Main {


    private  static void solver(InputReader sc, PrintWriter out) throws Exception {
            int n = sc.nextInt();
            int m = sc.nextInt();
            Set<Integer> hs = new HashSet<>();
            for(int i=0 ;i<m; i++){
                hs.add(sc.nextInt());
            }
            long dp[] = new long[n+1];
            long mod = 1000000007;
           if(hs.contains(0))
               dp[0] = 0;
           else
               dp[0] = 1;
           if(hs.contains(1))
               dp[1] = 0;
           else
               dp[1] = 1;
            for(int i=2;i<=n;i++){
                if(hs.contains(i)){
                    dp[i] = 0;
                }
                else{
                    dp[i] = (dp[i-1]+dp[i-2])%mod;
                }
            }
           /* for(int x : dp)
                out.print(x+"->");*/
            out.println(dp[n]%mod);
    }
    private  static long gcd(long a, long b){
        if(b==0)
            return a;
        else
            return gcd(b,a%b);
    }

    public static void main(String[] args) throws Exception{
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        solver(in,out);
        out.close();
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong(){
            return Long.parseLong(next());
        }

        public long[] readLongArr(int n){
            long arr[] = new long[n];
            for(int i=0; i<n; i++){
                arr[i] = nextLong();
            }
            return arr;
        }
        public int[] readIntArr(int n){
            int arr[] = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = nextInt();
            }
            return arr;
        }
    }
}
class Pair implements Comparable<Pair>{
    int x;
    String s;
    Pair(int x, String s){
        this.x = x;
        this.s = s;
    }
    public int compareTo(Pair p){
        return this.x-p.x;
    }
}
