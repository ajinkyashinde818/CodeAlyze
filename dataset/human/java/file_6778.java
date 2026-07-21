import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int k = Integer.parseInt(scanner.next());
        int n = Integer.parseInt(scanner.next());
        int[] a = new int[n];
        int cost;
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(scanner.next());
        }
        cost = k - Math.abs(k-a[n-1]+a[0]);
        for (int i = 1; i < n; i++) {
            cost = Math.min(cost, k - Math.abs(a[i]-a[i-1]));
        }
        System.out.println(cost);
    }
}
