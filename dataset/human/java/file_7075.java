import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int n = in.nextInt();
        int[] a = new int[n];
        for(int i=0; i<n; i++) {
            a[i] = in.nextInt();
        }
        Arrays.sort(a);
        int max = a[0] + (k-a[n-1]);
        int sum = max;
        for(int i=1; i<n; i++) {
            max = Math.max(max, a[i]-a[i-1]);
            sum += a[i]-a[i-1];
        }
        System.out.println(sum-max);
    }
}
