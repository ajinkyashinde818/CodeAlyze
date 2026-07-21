import java.awt.*;
import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;

public class Main {
    static Map<Long,Integer> map;
    public static void main(String[] args) throws Exception {
        FastReader sc = new FastReader();
        long n=sc.nextLong();
        map=new HashMap<>();
        f(n);
        long ans=0;
        for (Map.Entry<Long,Integer> e:map.entrySet()){
            int f=e.getValue();
            int c=0;
            boolean ok=true;
            while (f>0){
                c++;
                f-=c;
                if (f<0)ok=false;
            }
            ans+=c;
            if (!ok)ans--;
        }
        System.out.println(ans);

    }

    static void f(long a){
        for (long i=2;i*i<=a;i++){
            while (a%i==0){
                map.put(i,map.getOrDefault(i,0)+1);
                a/=i;
            }
        }
        if (a>1)map.put(a,map.getOrDefault(a,0)+1);
    }
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
