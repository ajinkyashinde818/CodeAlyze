import java.util.*;
import java.io.*;
 
public class Main {
    static int n,g;
    static int[] p,c;
    static int ans = Integer.MAX_VALUE;
    public static void main(String[] args) throws Exception {
        FastScanner sc = new FastScanner(System.in);
        n = sc.nextInt();
        g = sc.nextInt();
        p = new int[n];
        c = new int[n];
        for(int i = 0; i < n; i++){
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        dfs(0,0,0,0);
        System.out.println(ans);
    }
    
    public static void dfs(int index, int unusedmax, int point, int count){
        if(n == index){
            if(point >= g){
                ans = Math.min(ans,count);
            }else if(point < g &&unusedmax != 0){
                int tmp = (g-point)/unusedmax;
                tmp += (g-point)%unusedmax != 0 ? 1 : 0;
                if(tmp <= p[unusedmax/100-1]){
                    ans = Math.min(ans,count+tmp);
                }
            }
            return;
        }
        dfs(index+1,unusedmax,point+(index+1)*100*p[index]+c[index], count+p[index]);
        dfs(index+1,(index+1)*100,point,count);
        return;
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
