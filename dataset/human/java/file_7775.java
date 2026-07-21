import javax.swing.plaf.synth.SynthEditorPaneUI;
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[]a = new int[n];
        for (int i =0;i<n;i++){
            a[i]=sc.nextInt()-1;
        }
        int[]c= new int[n];
        Arrays.fill(c,-1);
        int s =0;
        int cur =0;
        while (k>0){
            if (c[s]==-1){
                c[s]=cur++;
                s=a[s];
                k--;
            }
            else {
                k%=(cur-c[s]);
                cur++;
                if (k>0){
                    s=a[s];
                    k--;
                }
            }
        }
        pw.println(s+1);
        pw.flush();
    }
    static long gcd(long a,long b){
        if (a==0)
            return b;
        return gcd(b%a,a);
    }
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public int[] nextIntarr(int n)throws Exception{
            int[]a = new int[n];
            for (int i =0;i<n;i++)
                a[i]=nextInt();
            return a;
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
