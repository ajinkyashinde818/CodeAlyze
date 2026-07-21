import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int ans = 0;
            int n = in.nextInt();
            int[] a = new int[n];
            int[] c = new int[n - 1];

            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            for (int i = 0; i < n; i++) {
                ans += in.nextInt();
            }

            for (int i = 0; i < n - 1; i++) {
                c[i] = in.nextInt();
            }

            for (int i = 1; i < n; i++) {
                if (a[i] - a[i - 1] == 1) {
                    ans += c[a[i - 1] - 1];
                }
            }

            System.out.println(ans);
        }
    }
}
