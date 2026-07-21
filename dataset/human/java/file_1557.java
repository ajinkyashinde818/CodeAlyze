import java.util.*;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[]$) {
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        String[] a = new String[n];
        Arrays.setAll(a, i -> scanner.next());
        String[] b = new String[m];
        Arrays.setAll(b, i -> scanner.next());
        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j <= n - m; j++) {
                boolean f = true;
                for (int k = 0; k < m; k++) {
                    f &= a[i + k].substring(j, j + m).equals(b[k]);
                }
                if (f) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}
