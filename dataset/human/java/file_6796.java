import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = Integer.parseInt(sc.next());
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        int sub = 0;
        int bef = 0;
        int temp = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            temp = Integer.parseInt(sc.next());
            if (i != 0) {
                ans += temp - bef;
                sub = Math.max(sub, temp - bef);
            }
            if (i == n - 1) {
                ans += Math.abs(k - temp + a[0]);
                sub = Math.max(sub, Math.abs(k - temp + a[0]));
            }
            bef = temp;
            a[i] = temp;
        }
        System.out.println(ans - sub);
    }
}
