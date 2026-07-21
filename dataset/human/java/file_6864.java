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
        int max = a[0] + (k - a[n-1]);
        for (int i = 1; i < n; i++) {
            int d = a[i] - a[i-1];
            if(max < d) max = d;
        }
        System.out.println(k-max);
        sc.close();

    }

}
