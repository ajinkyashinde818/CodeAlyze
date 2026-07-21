import java.util.*;

public class Main {
    public void main(Scanner sc) {
        int n, cnt = 0;
        long a, sum = 0, min = Long.MAX_VALUE;

        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            a = sc.nextLong();
            if (a < 0) {
                cnt++;
            }
            if (Math.abs(a) <= min) {
                min = Math.abs(a);
            }

            sum += Math.abs(a);
        }

        System.out.println(cnt % 2 == 0 ? sum : sum - min * 2);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        new Main().main(sc);
        sc.close();
    }
}
