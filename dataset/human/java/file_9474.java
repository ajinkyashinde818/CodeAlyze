import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        Integer[] d1 = new Integer[n];
        Integer[] d2 = new Integer[n];
        for (int i = 0; i < n; i++) {
            d1[i] = Integer.parseInt(sc.next());
            d2[i] = Integer.parseInt(sc.next());
        }
        sc.close();

        // 主処理
        boolean judge = false;
        int renzoku = 0;
        for (int i = 0; i < n; i++) {
            if (d1[i] == d2[i]) {
                renzoku++;
            } else {
                renzoku = 0;
            }
            if (renzoku == 3) {
                judge = true;
                break;
            }
        }
        String result = judge ? "Yes" : "No";

        // 出力
        System.out.println(result);
    }
}
