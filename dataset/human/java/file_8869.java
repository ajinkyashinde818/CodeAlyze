import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class pair implements Comparable<pair>{
        int x,id;
        pair(int a,int b){
            x=a;
            id=b;
        }
        public int compareTo(pair o) {

            return x-o.x==0?id-o.id:x-o.x;
        }
        public String toString(){
            return x+" "+id;
        }
    }
    static ArrayList<Integer> primes;
    static int[] isComposite;
    static HashMap<Integer,Integer>[]pr;
    static void sieve(int N)	// O(N log log N)
    {
        isComposite = new int[N+1];
        isComposite[0] = isComposite[1] = 1;			// 0 indicates a prime number
        primes = new ArrayList<Integer>();

        for (int i = 2; i <= N; ++i) {                //can loop till i*i <= N if primes array is not needed O(N log log sqrt(N))
            if (isComposite[i] == 0)                    //can loop in 2 and odd integers for slightly better performance
            {
                primes.add(i);
                pr[i].put(i,1);
                for (int j = i * 2; j <= N; j += i)    // j = i * 2 will not affect performance too much, may alter in modified sieve
                {
                    isComposite[j] = 1;
                    int x = j;
                    int e = 0;
                    while (x % i == 0) {
                        x /= i;
                        e++;
                    }
                    pr[j].put(i,e);
                }
            }
        }
    }
    public static void main(String[] args) throws IOException, InterruptedException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c= sc.nextInt();
        int x=0;
        for (int i =Math.min(a,b);i>=1;i--){
            if (a%i==0&&b%i==0){
                x++;
                if (x==c)pw.println(i);
            }
        }

        pw.flush();

    }
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public boolean ready() throws IOException {
            return br.ready();
        }

    }
}
