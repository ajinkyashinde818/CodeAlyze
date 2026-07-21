import java.io.*;
import java.util.*;

public class Main {
    public static PrintWriter out;
    public static FastScanner in;

    private void solve(){
        int n = in.nextInt();
        int m = in.nextInt();

        String[] s = new String[n];
        for(int i=0;i<n;i++){
            s[i] = in.nextLine();
        }

        String[] t = new String[m];
        for(int i=0;i<m;i++){
            t[i] = in.nextLine();
        }

        for(int x = 0; x<=n-m;x++){
            for(int y=0;y<=n-m;y++){
                int k;
                for(k=0;k<m;k++){
                    String sb1 = s[x+k].substring(y,y+m);
                    if(!sb1.equals(t[k])) break;
                }
                if(k == m){
                    out.print("Yes");
                    return;
                }
            }
        }
        out.print("No");
    }

    private void runIO() {
        in = new FastScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        solve();
        out.close();
    }
    private static class FastScanner {
        BufferedReader bufferedReader;
        StringTokenizer stringTokenizer;

        private FastScanner() {
            bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        }

        private String next() {
            if (stringTokenizer == null || !stringTokenizer.hasMoreElements()) {
                try {
                    stringTokenizer = new StringTokenizer(bufferedReader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return stringTokenizer.nextToken();
        }

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private long nextLong() {
            return Long.parseLong(next());
        }

        private String nextLine() {
            String ret = "";
            try {
                ret = bufferedReader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return ret;
        }
    }

    public static void main(String[] args) {
        new Main().runIO();
    }
}
