import java.lang.Math;
import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        Integer[] A = new Integer[N];

        int numberOfNegatives = 0;
        int minAbs = Integer.MAX_VALUE;

        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();
            if (A[i] < 0) { numberOfNegatives++; }
            int abs = Math.abs(A[i]);
            if (abs < minAbs) { minAbs = abs; }
        }

        long answer = 0;
        for (int i = 0; i < N; i++) {
            answer += Math.abs(A[i]);
        }

        // If the number of negatives are even, all negatives could be flipped to positives
        // if odd, one must be retained somewhere in the array
        if (numberOfNegatives % 2 == 1) {
            answer -= (2 * minAbs);
        }

        System.out.println(answer);
    }
}
