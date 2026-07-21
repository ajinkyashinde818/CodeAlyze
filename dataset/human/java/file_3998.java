// package app;

import java.math.BigDecimal;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

    public static void main(final String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        long N = sc.nextLong();
        // long K = sc.nextLong();
        int[] A = new int[(int)N];
        int[] B = new int[(int)N];
        int[] C = new int[(int)N];

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        for (int i = 0; i < N; i++) {
            B[i] = sc.nextInt();
        }

        for (int i = 0; i < N - 1; i++) {
            C[i] = sc.nextInt();
        }

        int score = 0;
        for (int i = 0; i < N; i++) {
            score += B[A[i] - 1];

            if (i > 0 && A[i] - 1 == A[i - 1]) {
                score += C[A[i - 1] - 1];
            }
        }

        System.out.println(score);
    }
}
