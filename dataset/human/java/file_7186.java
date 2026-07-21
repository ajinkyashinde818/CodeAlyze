import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        int min = 2 * k;
        for (int i = 0; i < n; i++) {
            int tmp = 0;

            // cw
            int l = i - 1;
            if (l < 0) {
                l = n - 1;
                tmp = a[l] - a[i];
            } else {
                tmp = k - a[i] + a[l];
            }
            min = Math.min(min, tmp);

            // ccw
            int r = i + 1;
            if (r >= n) {
                r = 0;
                tmp = a[i] - a[r];
            } else {
                tmp = a[i] + k - a[r];
            }
            min = Math.min(min, tmp);
        }
        
        System.out.println(min);
    }
}
