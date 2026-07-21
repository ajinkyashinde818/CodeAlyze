import java.util.Arrays;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = Integer.parseInt(sc.next());
        int n = Integer.parseInt(sc.next());
        int[] a = new int[n];
        int[] b = new int[n];
        int result = 0;
        for (int i = 0; i < n; i++)
            a[i] = Integer.parseInt(sc.next());
        for (int i = n-1; i > 0; i--)
            b[i] = a[i] - a[i-1];
        b[0] = k-a[n-1]+a[0];
        Arrays.sort(b);
        for (int i = 0; i < n-1; i++)
            result += b[i];
        System.out.println(result);
    }
}
