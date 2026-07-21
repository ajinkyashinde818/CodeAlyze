import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] arr = new int[n];
        arr[0] = sc.nextInt();
        int max = 0;
        for (int i = 1; i < n; i++) {
            arr[i] = sc.nextInt();
            max = Math.max(max, arr[i] - arr[i - 1]);
        }
        max = Math.max(max, arr[0] - arr[n - 1] + k);
        System.out.println(k - max);
    }
}
