import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);
        long N;
        N = sc.nextLong();
        long[] A = new long[(int)(N)];
        for(int i = 0 ; i < N ; i++){
                A[i] = sc.nextLong();
        }
        long[] B = new long[(int)(N)];
        for(int i = 0 ; i < N ; i++){
                B[i] = sc.nextLong();
        }
        long[] C = new long[(int)(N-1)];
        for(int i = 0 ; i < N-1 ; i++){
                C[i] = sc.nextLong();
        }
        solve(N, A, B, C);
    }

    static void solve(long N, long[] A, long[] B, long[] C){
        long ans = 0;
        long ex = N+1;
        for (long a : A) {
            ans += B[(int)(a) - 1];
            if (a - ex == 1) {
                ans += C[(int)(ex) - 1];
            }
            ex = a;
        }
        System.out.println(ans);
    }
}
