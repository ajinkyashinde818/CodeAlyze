import java.awt.*;
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        FastReader sc = new FastReader();
        int k=sc.nextInt(),n=sc.nextInt();
        int a[]=new int[n];
        for (int i=0;i<n;i++){
            a[i]=sc.nextInt();
        }
        int min=-1;
        for (int i=0;i<n;i++){
           if (i==0){
               min=Math.min(k-(a[i+1]-a[i]),a[n-1]);
               continue;
           }
           if (i==n-1){
               min=Math.min(min,Math.min(a[n-1]-a[0],k-(a[i]-a[i-1])));
               continue;
           }
           min=Math.min(min,Math.min(k-(a[i]-a[i-1]),k-(a[i+1]-a[i])));
        }
        System.out.println(min);


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
