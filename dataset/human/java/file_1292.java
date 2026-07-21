import java.util.Scanner;

public class Main {
    static int n;
    static long[] sumA;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sumA = new long[n+1];
        sumA[0] = sc.nextInt();
        for (int i = 1; i < n; i++) {
            sumA[i] = sumA[i-1] + sc.nextInt();
        }
        long ans = Integer.MAX_VALUE;
        for (int i = 0; i < n - 1; i++) {
            ans = Math.min(ans, Math.abs(sumA[i] - (sumA[n-1] - sumA[i])));
        }
        System.out.println(ans);
    }
}
