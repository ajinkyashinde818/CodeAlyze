import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        long sum = 0;
        int max = 0;
        a[0] = sc.nextInt();
        for (int i = 1; i < n; i++) {
            a[i] = sc.nextInt();
            sum += a[i] - a[i-1];
            max = Math.max(max, a[i] - a[i-1]);
        }
        int se = k - a[n-1] + a[0];
        sum += se;
        max = Math.max(max, se);
        System.out.println(sum-max);
    }
}
