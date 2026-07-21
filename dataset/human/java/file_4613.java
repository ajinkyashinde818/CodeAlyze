import java.util.Scanner;

public class Main {
    private static int a, b, c;
    private static int count;

    public static void main(String[] args) {
        init();

        if (a + b >= c) {
            count += (c + b);
        } else {
            count += (a + 2 * b);
            if (c > a + b) count++;
        }

        System.out.println(count);
    }

    public static void init() {
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        count = 0;
    }
}
