import java.util.Scanner;

public class Main {

    public static void main(final String[] args) {

        try (final Scanner sc = new Scanner(System.in)) {
            int N = sc.nextInt();
            int negaCount = 0;
            long minAbs = Long.MAX_VALUE;
            long sum = 0;
            for (int i = 0; i < N; i++) {
                long ai = sc.nextInt();
                if (ai < 0L) {
                    negaCount += 1;
                }
                long abs = Math.abs(ai);
                minAbs = Math.min(minAbs, abs);
                sum += abs;
            }
            if (negaCount % 2 != 0) {
                sum -= minAbs * 2L;
            }
            System.out.println(sum);
        }
    }
}
