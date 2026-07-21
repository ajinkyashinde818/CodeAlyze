import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        FastScanner scanner = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i< n; i++) arr[i] = scanner.nextInt();
        int[] b = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
            sum += b[i];
        }
        int[] c = new int[n-1];
        for(int i = 0; i < n-1; i++) c[i] = scanner.nextInt();
        for(int i = 1; i < n; i++) {
            if (arr[i] == arr[i-1] + 1) sum += c[arr[i-1]-1];
        }
        out.println(sum);
        out.flush();
    }
    
    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;
        
        public FastScanner(Reader in) {
            br = new BufferedReader(in);
        }
        
        public FastScanner() {
            this(new InputStreamReader(System.in));
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
        
        String readNextLine() {
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
