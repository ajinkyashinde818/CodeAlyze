import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int R = scanner.nextInt();

        if (N >= 10) {
            System.out.println(R);
        } else {
            int temp = 100 * (10 - N);
            System.out.println(R + temp);
        }
    }
}
