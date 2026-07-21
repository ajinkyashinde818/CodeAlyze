import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int r = scanner.nextInt();

        int result;
        if (n >= 10) {
            result = r;
        } else {
            result = 100 * (10 - n) + r;
        }
        System.out.println(result);
    }
}
