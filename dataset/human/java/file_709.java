import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        try (Scanner sc = new Scanner(System.in)) {
            int N = sc.nextInt();
            int R = sc.nextInt();

            int ans = R;
            if (N < 10) {
                ans += 100 * (10 - N);
            }

            System.out.println(ans);
        }
    }

}
