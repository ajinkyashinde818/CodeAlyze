import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        long k = scanner.nextLong();
        long n = scanner.nextLong();

        long max = 0;
        long sum = 0;
        long first = 0;
        long previous = 0;

        for (long i = 0; i < n; i++) {
            long a = scanner.nextLong();
            if (i == 0) {
                max = a;
                sum = a;
                first = a;
                previous = a;

            } else {
                long aida = a - previous;
                previous = a;
                sum = sum + aida;

                if (aida > max) {
                    max = aida;
                }
            }
        }
        long saigo = k - sum + first;

        if (saigo > max) {
            max = saigo;
        }

        System.out.println(k - max);
    }
}
