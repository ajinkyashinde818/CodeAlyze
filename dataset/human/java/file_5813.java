// package app;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

    public static void main(final String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);

        final String S = sc.next();
        // final int A = sc.nextInt();

        boolean result = false;
        if (S.contains("a") && S.contains("b") && S.contains("c")) {
            result = true;
        }

        // System.out.println();
        System.out.println(result ? "Yes" : "No");

        // System.out.println(A <= X && A + B >= X ? "YES" : "NO");

    }
}
