import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] d = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        d[0] = k - a[n - 1] + a[0];
        for (int i = 1; i < n; i++) {
            d[i] = a[i] - a[i - 1];
        }
        int max = d[0];
        for (int i = 1; i < n; i++) {
            if(d[i] > max){
                max = d[i];
            }
        }
        System.out.println(k - max);
    }
}
