import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        int[] b = new int[n];
        int[] c = new int[n - 1];

        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(sc.next());
        }
        for (int i = 0; i < n; i++) {
            b[i] = Integer.parseInt(sc.next());
        }
        for (int i = 0; i < n - 1; i++) {
            c[i] = Integer.parseInt(sc.next());
        }

        int prev = -1;
        int ret = 0;
        for (int an : a) {
            ret += b[an - 1];
            if (prev == an - 1) {
                ret += c[prev - 1];
            }
            prev = an;
        }

        System.out.println(ret);

    }
}
