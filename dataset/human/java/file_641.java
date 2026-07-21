import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        // ##### 初期読み込み #######################################################################

        // 1行 文字 複数 ----------------------------------------------------------------------------
        String[] stringArray = scanner.nextLine().split(" ");

        int n = Integer.parseInt(stringArray[0]);
        int r = Integer.parseInt(stringArray[1]);


        // ##### メイン処理 #######################################################################

        int result = 0;
        if (n >= 10) {
            result = r;
        } else {
            result = r + 100 * (10 - n);
        }
        System.out.println(result);

    }
}
