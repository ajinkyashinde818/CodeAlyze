import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] diff = new int[n];

        int max_diff = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if(i > 0) {
                diff[i] = a[i] - a[i-1];
                max_diff = Math.max(max_diff, diff[i]);
            }
        }
        diff[0] = a[0] + k - a[a.length-1];
        max_diff = Math.max(max_diff, diff[0]);
        System.out.println(Arrays.stream(diff).sum() - max_diff);
    }
}
