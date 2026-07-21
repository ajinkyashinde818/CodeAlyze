import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long k = sc.nextLong();
        int n = sc.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
        }

        long maxIdx = n - 1;
        long maxVal = k - a[n - 1] + a[0];
        for (int i = 0; i < n - 1; i++) {
            long val = a[i + 1] - a[i];
            if (val > maxVal) {
                maxIdx = i;
                maxVal = val;
            }
        }
        System.out.println(k - maxVal);
    }

}
