import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int k = Integer.parseInt(scan.next());
        int n = Integer.parseInt(scan.next());

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(scan.next());
        }

        scan.close();

        // 最後と最初の距離を初期値とする
        int max = a[0] + (k - a[n - 1]);
        for (int i = 0; i < n-1; i++) {
            int distance = a[i + 1] - a[i];
            if (max < distance) {
                max = distance;
            }
        }

        System.out.println(k - max);
    }

}
