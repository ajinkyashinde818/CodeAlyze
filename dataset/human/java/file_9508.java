import java.util.Scanner;

public class Main {
    public static void main(String... args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();

        int streak = 0;
        for (int i = 0; i < N; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();

            if (a == b) {
                streak++;
            } else {
                streak = 0;
            }

            if (streak == 3) {
                System.out.println("Yes");
                return;
            }
        }

        System.out.println("No");
    }
}
