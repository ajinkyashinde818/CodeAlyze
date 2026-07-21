import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[m];
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }

        List<Integer> from1 = new ArrayList<>();
        Set<Integer> ton = new HashSet<>();
        for (int i = 0; i < m; i++) {
            if (a[i] == 1) {
                from1.add(b[i]);
            }
            if (b[i] == n) {
                ton.add(a[i]);
            }
        }
        for (Integer island : from1) {
            if (ton.contains(island)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }

}
