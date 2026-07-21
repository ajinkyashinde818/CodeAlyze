import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int ans = a[a.length - 1] - a[0];
        int dis1 = 0;
        int dis2 = 0;
        int dis = 0;
        for (int i = 1; i < n-1; i++) {
            dis1 = k - a[i] + a[i - 1];
            dis2 = a[i] + k - a[i+1];
            dis = Math.min(dis1, dis2);
            ans = Math.min(ans, dis);
        }
        System.out.println(ans);
    }
}
