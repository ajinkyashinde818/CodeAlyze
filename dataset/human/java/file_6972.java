import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] dif = new int[n];
        for (int i = 0; i < n - 1; i++) {
            dif[i] = a[i + 1] - a[i];
        }
        dif[n - 1] = k - a[n - 1] + a[0];
        int max = dif[0];
        for (int i = 1; i < n; i++) {
            max = Math.max(max, dif[i]);
        }
        System.out.println(k - max);
        sc.close();
    }
}
