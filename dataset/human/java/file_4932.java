import java.util.Scanner;

/**
 * Double Factorial
 */
public class Main {

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            long N = sc.nextLong();

            if (N % 2 == 1) {
                System.out.println(0);
                return;
            }

            long c = 0;
            long x = 10;
            while (true) {
                if (N / x == 0) {
                    break;
                }

                c += N / x;
                x *= 5;
            }

            System.out.println(c);
        }
    }

}
