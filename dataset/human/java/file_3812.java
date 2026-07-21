import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        // 主処理
        int result = 0;
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s.charAt(l) != s.charAt(r)) {
                if (s.charAt(l) == 'x') {
                    l++;
                    result++;
                } else if (s.charAt(r) == 'x') {
                    r--;
                    result++;
                } else {
                    result = -1;
                    break;
                }
            } else {
                l++;
                r--;
            }
        }

        // 出力
        System.out.println(result);
        sc.close();
    }
}
