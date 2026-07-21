import java.util.Scanner;

public class Main {
    public static void main(String... args) {
        // 入力
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        int div = 0;
        if (a > b) div = b;
        else div = a;

        for (int i = div; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
                k--;
                if (k == 0) System.out.println(i);
            }
        }
    }
}
