import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);


    public static void main(String[] args) {
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int max = Integer.MIN_VALUE;
        int count = 0;
        for (int i = 1; i < n; i++) {
            int value = a[i] - a[i - 1];
            count += value;
            max = Math.max(max, value);
        }
        int value = k - a[n - 1] + a[0];
        count += value;
        max = Math.max(max, value);
        System.out.println(count - max);
    }
}
