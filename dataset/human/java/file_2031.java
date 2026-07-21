import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        long N = scanner.nextLong();
        if (N <= 1) {
            System.out.println(0);
            return;
        }

        long sqrt = (long) Math.sqrt(N);
        int count = 0;
        for (long i = 2 ; i * i <= N ; i++) {
            if (N % i == 0) {
                long z = i;
                while (N % z == 0) {
                    count++;
                    N /= z;
                    z *= i;
                }
                while (N % i == 0) {
                    N /= i;
                }
            }
        }

        if (N > 1) count++;
        System.out.println(count);
    }

    static void eratosthenes(int N) {
        boolean[] numbers = new boolean[N + 1];
        for (int i = 0 ; i <= N ; i++) {
            numbers[i] = true;
        }

        int sqrt = (int) Math.sqrt(N);
        for (int i = 2 ; i <= sqrt ; i++) {
            if (numbers[i]) {
                for (int j = i * i ; j <= N ; j+= i) {
                    numbers[j] = false;
                }
            }
        }

        for (int i = 1 ; i <= N ; i++) {
            if (numbers[i]) {
                System.out.printf("%3d ", i);
            } else {
                System.out.print("    ");
            }
            if (i % 10 == 0) {
                System.out.println();
            }
        }

    }
}
