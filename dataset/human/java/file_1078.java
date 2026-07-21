import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;
public class Main{

    static long MOD = 1000000007L;
    static long [] fac;
    static int[][] dir = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static long lMax = 0x3f3f3f3f3f3f3f3fL;
    static int iMax = 0x3f3f3f3f;
    static HashMap <Long, Long> memo = new HashMap();
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        // Start writing your solution here. -------------------------------------
        //int t = sc.nextInt();
        int t = 1;
        /*
        boolean notP[] = new boolean[100001];
        for(int i = 2; i < 400; i++){
            if(notP[i]) continue;
            for(int j = 2; i * j <= 100000; j++){
                notP[i * j] = true;
            }
        }
        ArrayList <Integer> primes = new ArrayList<>();
        for(int i = 2; i <= 100000; i++)
            if(!notP[i])
                primes.add(i);*/
        while(t-- > 0){
            int n = sc.nextInt();
            int a[] = new int[n];
            int b[] = new int[n];
            int cntA[] = new int[n + 1];
            int cntB[] = new int[n + 1];
            int[] last = new int[n + 1];
            int[] first = new int[n + 1];
            Arrays.fill(first, -1);
            Arrays.fill(last, -1);
            for(int i = 0; i < n; i++)
            {
                a[i] = sc.nextInt();
                cntA[a[i]]++;
                last[a[i]] = i;
            }
            for(int i = 0; i < n; i++)
            {
                b[i] = sc.nextInt();
                cntB[b[i]]++;
                if(first[b[i]] == -1)
                    first[b[i]] = i;
            }
            boolean imposs = false;
            int minS = 0;
            for(int i = 1; i <= n; i++) {
                if (cntA[i] + cntB[i] > n) {
                    imposs = true;
                    break;
                }
                if(last[i] != -1 && first[i] != -1)
                    minS = Math.max(minS, last[i] + 1 - first[i]);
            }
            if(imposs){
                out.println("No");
                continue;
            }
            out.println("Yes");
            int[] c = new int[n];
            for(int i = 0; i < n; i++)
            {
                int tmp = (minS + i) % n;
                c[tmp] = b[i];
            }
            for(int i = 0; i < n; i++){
                out.print(c[i] + " ");
            }
            out.println("");
        }
        out.close();
    }
    public static long C(int n, int m)
    {
        if(m == 0 || m == n) return 1l;
        if(m > n || m < 0) return 0l;
        long res = fac[n] * quickPOW((fac[m] * fac[n - m]) % MOD, MOD - 2) % MOD;

        return res;
    }
    public static long quickPOW(long n, long m)
    {
        long ans = 1l;
        while(m > 0)
        {
            if(m % 2 == 1)
                ans = (ans * n) % MOD;
            n = (n * n) % MOD;
            m >>= 1;
        }
        return ans;
    }
    public static int gcd(int a, int b)
    {
        if(a % b == 0) return b;
        return gcd(b, a % b);
    }
    public static long gcd(long a, long b)
    {
        if(a % b == 0) return b;
        return gcd(b, a % b);
    }
    public static long solve(long cur){
        return 0L;
    }
    //-----------PrintWriter for faster output---------------------------------
    public static PrintWriter out;
    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        long nextLong() {
            return Long.parseLong(next());
        }
        double nextDouble() {
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    //--------------------------------------------------------
}
