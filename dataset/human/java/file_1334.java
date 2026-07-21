import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String[] a = new String[n];
        String[] b = new String[m];
        for (int i = 0; i < n; i++) {
            a[i] = sc.next();
        }
        for (int i = 0; i < m; i++) {
            b[i] = sc.next();
        }
        for (int i = 0; i < n - m + 1; i++) {
            for (int j = 0; j < a[0].length() - b[0].length() + 1; j++) {
                int count = 0;
                for (int k = 0; k < m; k++) {
                    if (b[k].equals(a[k + i].substring(j, b[k].length() + j)))
                        count++;
                    else
                        ;
                }
                if (count == m) {
                    System.out.println("Yes");
                    System.exit(0);
                }
            }
        }
        System.out.println("No");
    }
}
