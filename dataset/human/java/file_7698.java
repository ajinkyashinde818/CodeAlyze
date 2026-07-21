import java.io.*;
import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
 
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];
 
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt()-1;
        }
 
        int cnt = 0;
        int p = 0;
        int[] visit = new int[n];
        int[] history = new int[n];
        Arrays.fill(visit, -1);
        do {
            visit[p] = cnt;
            history[cnt] = p;
            p = a[p];
            cnt++;
        } while (visit[p] == -1);
 
        int dist = cnt - visit[p];
        int num = (int)((k - cnt) % dist + visit[p]);
        if (cnt > k)
            num = (int)k;
 
        System.out.println(history[num] + 1);
    }
 
    static class MyScanner {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 1 << 15);
        StringTokenizer tokenizer;
 
        String next() {
            try {
                while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                    tokenizer = new StringTokenizer(reader.readLine());
                }
            } catch (IOException ignored) {
            }
            return tokenizer.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
