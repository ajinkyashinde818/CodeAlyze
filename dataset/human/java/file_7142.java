import java.util.*;
import java.io.*;
import java.math.*;
import java.util.Collections;

class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] A = new int[N];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        int d1 = A[0] +  K - A[N - 1];

        long sum = 0;
        int longest = 0;
        for (int i = 0; i < N - 1; i++) {
            int d = (A[i + 1] - A[i]);
            if (longest < d) {
                longest = d;
            }
            sum += d;
            //System.out.println(String.format("sum,d= %d %d", sum, d));
        }
        sum += d1;
        //System.out.println(String.format("sum,d1=%d %d", sum, d1));
        if (longest < d1) {
            longest = d1;
        }

        System.out.println(sum - longest);
    }

}
