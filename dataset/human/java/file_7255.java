import java.io.IOException;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int n = in.nextInt();
        int[] arr = new int[n];
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }
        for (int i = 1; i < n; i++) {
            ans[i] = arr[i] - arr[i - 1];
        }
        ans[0] = k - arr[n - 1] + arr[0];

        int temp = 0;
        for (int i = 1; i < n; i++) {
            if (Math.max(ans[temp], ans[i]) == ans[i]) {
                temp = i;
            }
        }
        System.out.println(k - ans[temp]);
    }
}
