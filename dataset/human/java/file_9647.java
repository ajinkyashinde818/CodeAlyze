import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scan.nextInt();
            b[i] = scan.nextInt();
        }
        boolean ans = false;
        for (int i = 0; i + 2 < n; i++) {
            if (a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2]) ans = true;
        }
        System.out.println(ans ? "Yes" : "No");
    }
}
