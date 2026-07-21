import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int N = sc.nextInt();
            int R = sc.nextInt();

            int result = R;

            if (N < 10) {
                result += 100 * (10 - N);
            }

            System.out.println(result);

        }
    }

}
