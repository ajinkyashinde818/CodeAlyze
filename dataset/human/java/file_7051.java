import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int n = in.nextInt();
        int a[] = new int[200009];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        a[n] = k + a[0];
        int ans = 1000000009;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, k - (a[i+1] - a[i]));
        }
        System.out.println(ans);
    }
}
