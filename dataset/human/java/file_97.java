import java.util.Arrays;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        long ans = 0;
        int min = 1500000000;
        int hucnt = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (a[i] < 0) {
                hucnt++;
            }

            a[i] = Math.abs(a[i]);
            if (min > a[i]) {
                min = a[i];
            }
            ans += a[i];
        }
        Arrays.sort(a);
        if (hucnt % 2 == 1) {
            ans = ans - a[0] * 2;
        }
        System.out.println(ans);
        sc.close();
    }
}
