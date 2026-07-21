import java.util.Scanner;

public class Main {
    private static long WARU = 1000000007;
    public static void main(final String[] args) {
        final Scanner scanner = new Scanner(System.in);
        final int count = scanner.nextInt();
        final int fallCount = scanner.nextInt();

        final long[] steps = new long[count + 1];

        for (int i = 1; i < steps.length; i++) {
            steps[i] = 0;
        }

        steps[0] = 1;

        for (int i = 0; i < fallCount; i++) {
            steps[scanner.nextInt()] = -1;
        }

        for (int i = 0; i < count; i++) {
            if (steps[i] == -1) {
                continue;
            }

            if (i == count - 1) {
                steps[i + 1] += steps[i];
                break;
            }

            if (steps[i + 1] == -1 && steps[i + 2] == -1) {
                System.out.println(0);
                return;
            }

            if (steps[i + 2] != -1) {
                steps[i + 2] += steps[i] % WARU;
            }

            if (steps[i + 1] != -1) {
                steps[i + 1] += steps[i] % WARU;
            }
        }

        System.out.println(steps[count] % WARU);
    }
}
