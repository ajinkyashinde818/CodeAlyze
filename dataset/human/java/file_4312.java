import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        int N = sc.nextInt();
        int[] A = new int[N];
        int[] B = new int[N];
        int[] C = new int[N-1];

        for (int i=0; i<N; i++){
            A[i] = sc.nextInt()-1;
        }
        for (int i=0; i<N; i++){
            B[i] = sc.nextInt();
        }
        for (int i=0; i<N-1; i++){
            C[i] = sc.nextInt();
        }

        int ans = B[A[0]];
        int curIdx = A[0];
        for (int i=1; i<N; i++){
            ans += B[A[i]];
            if (A[i] == curIdx + 1){
                ans += C[A[i-1]];
            }
            curIdx = A[i];
        }

        System.out.println(ans);

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
