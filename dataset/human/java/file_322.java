import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int negatives = 0;
        int minAbs = Integer.MAX_VALUE;
        boolean hasZero = false;

        long sum = 0;

        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (a < 0) negatives++;
            if (a == 0) hasZero = true;
            sum += Math.abs(a);
            minAbs = Math.min(minAbs, Math.abs(a));
        }

        if (hasZero || negatives % 2 == 0) {
            System.out.println(sum);
        } else {
            System.out.println(sum - 2 * minAbs);
        }
    }
}
