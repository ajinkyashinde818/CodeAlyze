import java.io.*;
import java.util.*;
public class Main {
    private static MyScanner scanner;
 
    public static void main (String[] args){
        Main instance = new Main();
        scanner = instance.new MyScanner();
        instance.solve();
    }
 
    private void solve() {
        try {
            int K = scanner.nextInt();
            int S = scanner.nextInt();
            int count = 0;
            for (int i = 0; i <= K; i++) {
                int X = i;
                for (int j = 0; j <= K; j++) {
                    int Y = j;
                    if (X + Y > S) {
                        break;
                    }
                    if (S - X - Y <= K) {
                        count++;
                    }
                }
            }
            System.out.println(count);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
 
    private class MyScanner {
        String[] s;
        int i;
        BufferedReader br;
        String reg = " ";
 
        MyScanner () {
            s = new String[0];
            i = 0;
            br = new BufferedReader(new InputStreamReader(System.in));
        }
 
        public String next() throws IOException {
            if (i < s.length) return s[i++];
            String line = br.readLine();
            while (line.equals("")) {
                line = br.readLine();
            }
            s = line.split(reg, 0);
            i = 0;
            return s[i++];
        }
 
        public int nextInt() throws NumberFormatException, IOException {
            return Integer.parseInt(next());
        }
 
        public double nextDouble() throws NumberFormatException, IOException {
            return Double.parseDouble(next());
        }
 
        public long nextLong() throws NumberFormatException, IOException {
            return Long.parseLong(next());
        }
    }
}
