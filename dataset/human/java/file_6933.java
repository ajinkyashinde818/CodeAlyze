// package app;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Scanner;
import java.util.StringJoiner;
import java.util.stream.Stream;

public class Main {

    public static void main(final String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();

        int N = sc.nextInt();

        int[] A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
        }

        int max = K - A[N - 1] + A[0];
        for (int i = 1; i < N; i++) {
            max = Math.max(max, A[i] - A[i - 1]);
        }

        int ans = K - max;
        System.out.println(ans);
    }
}
