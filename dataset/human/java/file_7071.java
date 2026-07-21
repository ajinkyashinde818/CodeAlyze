import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int k = scanner.nextInt();
        int n = scanner.nextInt();

        long first = 0;
        long previous = 0;
        long max = 0;
        long sum = 0;
        for (long i = 0; i < n; i++) {
            int a = scanner.nextInt();
            if (i == 0) {
                first = a;
                previous = a;
                max = a;
                sum = a;

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
