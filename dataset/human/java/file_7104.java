import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        Arrays.setAll(a, i -> sc.nextInt());
        sc.close();
        int max = k + a[0] - a[n-1];
        for (int i = 0; i < n-1; i++) {
            if (max < a[i+1]-a[i]) max = a[i+1]-a[i];
        }
        System.out.println(k-max);
    }
}
