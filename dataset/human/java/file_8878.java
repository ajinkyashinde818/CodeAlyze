import java.util.*;

public class Main {
    public static void main(String args[] ) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        int div = 1;
        for (int i = Math.min(a, b); i >= 0; i--) {
            if (a % i == 0 && b % i == 0 && --k == 0) {
                div = i;
                break;
            }
        }

        System.out.println(div);
    }
}
