import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] k = new long[n];
        long y = 0;
        for (int i = 0; i < n; i++) {
            k[i] = sc.nextLong();
            if (i != 0) {
                y += k[i];
            }
        }

        long x = k[0];
        long ans = Math.abs(x - y);
        for (int i = 1; i < n - 1; i++) {
            x += k[i];
            y -= k[i];
            ans = Math.min(ans, Math.abs(x - y));
        }
        System.out.println(ans);
    }

}
