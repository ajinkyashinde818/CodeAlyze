import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int x = Integer.parseInt(sc.next());
        sc.close();

        // 主処理
        boolean judge = x < 1200;
        String result = judge ? "ABC" : "ARC";

        // 出力
        System.out.println(result);
    }
}
