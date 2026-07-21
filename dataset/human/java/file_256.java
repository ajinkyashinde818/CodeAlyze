import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        final Integer[] values = Arrays.stream(scanner.nextLine().split(" "))
                .map(Integer::parseInt).toArray(Integer[]::new);

        int absMin = Integer.MAX_VALUE;
        int negativeCount = 0;

        long sum = 0;
        for (int i = 0; i < values.length; i++) {
            if (values[i] < 0) {
                negativeCount++;
            }

            absMin = Math.min(absMin, Math.abs(values[i]));
            sum += Math.abs(values[i]);
        }

        if (negativeCount % 2 == 0) {
            System.out.println(sum);
        } else {
            System.out.println(sum - absMin * 2);
        }
    }
}
