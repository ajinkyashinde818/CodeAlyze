import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final Scanner scanner = new Scanner(System.in);
        scanner.nextLine();

        final int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        final int[] b = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        final int[] c = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int previous = -2;
        int sum = 0;
        for (int i = 0; i < a.length; i++) {
            int eat = a[i] - 1;
            sum += b[eat];
            if (eat - 1 == previous) {
                sum += c[previous];
            }

            previous = eat;
        }

        System.out.println(sum);
    }
}
