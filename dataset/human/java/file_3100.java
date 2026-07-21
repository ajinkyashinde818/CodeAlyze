import java.util.*;
import java.lang.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[] = new int[m];
        int b[] = new int[m];
        TreeSet<Integer> set = new TreeSet<Integer>();
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        for (int i = 0; i < m; i++) {
            if (b[i] == n) {
                set.add(a[i]);
            }
        }
        boolean pos = false;
        for (int i = 0; i < m; i++) {
            if (a[i] == 1 && set.contains(b[i])) {
                pos = true;
                break;
            }
        }
        if (pos) {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}
