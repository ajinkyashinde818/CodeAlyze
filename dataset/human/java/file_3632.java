// package app;

import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

    public static void main(final String[] args) throws Exception {
        final Scanner sc = new Scanner(System.in);

        // final String N = sc.next();
        // final int M = sc.nextInt();
        // final int N = sc.nextInt();
        final int A = sc.next().charAt(0);
        final int B = sc.next().charAt(0);
        // final int D = sc.nextInt();

        // System.out.println();
        char op = '=';
        if ( A < B) {
            op = '<';
        } else if (A > B) {
            op = '>';
        }
        System.out.println(op);

        // System.out.println(A <= X && A + B >= X ? "YES" : "NO");

    }
}
