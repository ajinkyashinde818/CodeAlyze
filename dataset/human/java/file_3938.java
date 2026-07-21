import java.util.*;

class Main {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += sc.nextInt();
        }
        int[] c = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            c[i] = sc.nextInt();
        }
        sc.close();

        for (int i = 0; i < n - 1; i++) {
            if (a[i + 1] - a[i] == 1) {
                ans += c[a[i] - 1];
            }
        }

        System.out.println(ans);
    }
}
