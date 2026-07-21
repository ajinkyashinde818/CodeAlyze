import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        Arrays.sort(array);
        // 一番長い区間
        int max = 0;
        int maxStart = 0;
        for (int i = 1; i < n ; i++) {
            int v = array[i] - array[i - 1];
            if (v > max) {
                max = v;
                maxStart = i - 1;
            }
        }
        // 最後
        int v = (k - array[n - 1]) + array[0];
        if (v > max) {
            System.out.println(array[n - 1] - array[0]);
            return;
        }

        System.out.println(k - (array[maxStart + 1] - array[maxStart]));
    }
}
