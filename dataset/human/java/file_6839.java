import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        int N = sc.nextInt();
        int[] a = new int[N];

        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
        }

        int maxGap = 0;
        for (int i = N; i > 0;i--) {
            if (i > 1) {
                maxGap = Math.max(maxGap ,(a[i-1] - a[i-2])) ;
            }

            else {
                maxGap = Math.max(maxGap, (K - a[N-1] + a[0]));
            }
        }

        System.out.println(K-maxGap);
    }
}
