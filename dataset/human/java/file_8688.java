import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int A = scanner.nextInt();
            int B = scanner.nextInt();
            int k = scanner.nextInt();
            int cnt = 0;
            for (int i = (int)Math.max(A,B); i >0; i--) {
                if (A % i == 0 && B % i == 0) {
                    if (++cnt == k) {
                        System.out.println(i);
                        break;
                    }
                }
            }
        }
    }
}
