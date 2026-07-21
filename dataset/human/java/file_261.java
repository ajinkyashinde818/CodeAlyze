import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        long[] a = new long[n];

        long sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int j = scanner.nextInt();
            if (j < 0)
                count++;

            sum += a[i] = Math.abs(j);
        }

        if (count % 2 == 0) {
            System.out.println(sum);
        } else {
            long min = Arrays.stream(a).min().getAsLong();
            System.out.println(sum - min * 2);
        }
    }
}
