import java.util.*;

public class Main {
    public static void main(final String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        boolean flag = s == Math.pow(10, 9);
        for (int i = 0; i < k; i++) {
            System.out.print(s + " ");
        }
        for (int i = 0; i < n-k; i++) {
            if (flag) {
                System.out.println(1 + " ");
            } else {
                System.out.println(s+1 + " ");
            }
        }
    }
}
