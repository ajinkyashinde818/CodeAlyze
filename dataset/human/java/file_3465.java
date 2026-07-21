import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        String x = sc.next();
        String y = sc.next();
        sc.close();

        // 主処理
        int compare = x.compareTo(y);
        String result;
        if (0 < compare) {
            result = ">";
        } else if (compare < 0) {
            result = "<";
        } else {
            result = "=";
        }

        // 出力
        System.out.println(result);
    }
}
