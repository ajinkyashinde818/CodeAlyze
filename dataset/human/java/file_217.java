import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        try (Scanner in = new Scanner(System.in)) {
            int N = in.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = in.nextInt();
            }

            int countMinus = 0;
            int minValue = (int) 1e9 + 2;
            long sum = 0;
            for (int i = 0; i < N; i++) {
                if (A[i] < 0) {
                    countMinus++;
                }
                minValue = Math.min(minValue, Math.abs(A[i]));
                sum += Math.abs(A[i]);
            }

            System.out.println(countMinus % 2 == 0 ? sum : (sum - 2 * minValue));
        }
    }

}
