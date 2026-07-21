import java.util.*;
import java.io.*;
 
public class Main {
    static String[] word = {"dream", "dreamer", "erase", "eraser"};
    static int[] wordlen = {5,7,5,6};
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner(System.in);
        String s = sc.next();
        int nowIndex = s.length();
        while(nowIndex > 0){
            boolean flg = false;
            for(int i = 0; i < 4; i++){
                if(nowIndex >= wordlen[i] && s.substring(nowIndex-wordlen[i],nowIndex).equals(word[i])){
                    nowIndex -= wordlen[i];
                    flg = true;
                    break;
                }
            }
            if(!flg){
                break;
            }
        }
        System.out.println(nowIndex == 0 ? "YES" : "NO");
    }
}

class FastScanner {
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;
    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken("\n");
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
         return Double.parseDouble(next());
    }

    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    public long[] nextLongArray(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++)
            a[i] = nextLong();
        return a;
    } 
}
