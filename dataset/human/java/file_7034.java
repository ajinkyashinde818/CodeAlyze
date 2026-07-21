import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // ##### 初期読み込み #######################################################################

        // 1行 文字 複数 ----------------------------------------------------------------------------
        String[] stringArray = scanner.nextLine().split(" ");

        int k = Integer.parseInt(stringArray[0]);
        int n = Integer.parseInt(stringArray[1]);

        // 1行 数字 複数 ----------------------------------------------------------------------------
        String[] sArr = scanner.nextLine().split(" ");
        long[] a = new long[sArr.length];
        for (int i = 0; i < sArr.length; i++) {
            a[i] = Long.parseLong(sArr[i]);
        }

        // ##### メイン処理 #######################################################################

        long maxDistance = k - a[n-1] + a[0];
        long distance = 0;
        for (int i = 0; i < n-1; i++) {
            distance = a[i+1] - a[i];
            if (maxDistance < distance) {
                maxDistance = distance;
            }
        }
        System.out.println(k - maxDistance);
    }
}
