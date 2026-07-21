import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 整数の入力
        int a = sc.nextInt();
        int count = 0;
        String d;
        Boolean e = false;
        for (int i = 0; i < a; i++) {
            // スペース区切りの整数の入力
            int b = sc.nextInt();
            int c = sc.nextInt();

            if (b == c) {
                count += 1;
            } else {
                count = 0;
            }
            if (count == 3) {
                e = true;
            }
        }

        if (e) {
            d = "Yes";
        } else {
            d = "No";
        }

        // 出力
        System.out.println(d);
    }
}
