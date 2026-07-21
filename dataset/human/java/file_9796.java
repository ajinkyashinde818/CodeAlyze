import java.util.*;
import java.io.*;
 
public class Main {
    static boolean[][] used;
    static int[] ans;
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        Book[] book = new Book[n];
        for(int i = 0; i < n; i++){
            int c = sc.nextInt();
            int[] a = new int[m];
            for(int j = 0; j < m; j++){
                a[j] = sc.nextInt();
            }
            book[i] = new Book(c,a);
        }
        int ans = Integer.MAX_VALUE;
        int max = (int)Math.pow(2,n);
        for(int i = 0; i < max; i++){
            int[] tmp = new int[m];
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if((i >> j) % 2 == 1){
                    cnt += book[j].y;
                    for(int k = 0; k < m; k++){
                        tmp[k] += book[j].a[k];
                    }
                }
            }
            boolean bool = true;
            for(int ch : tmp){
                if(ch < x){
                    bool = false;
                    break;
                }
            }
            if(bool){
                ans = Math.min(ans,cnt);
            }
        }
        if(ans == Integer.MAX_VALUE){
            System.out.println(-1);
        }else{
            System.out.println(ans);
        }
    }
}

class Book{
    int y;
    int[] a;
    public Book(int y,int[] a){
        this.y = y;
        this.a = a;
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
