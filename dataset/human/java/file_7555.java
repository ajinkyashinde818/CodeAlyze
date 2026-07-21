import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] keyStrArr = new String[]{
                "dream",
                "dreamer",
                "erase",
                "eraser",
        };

        String sReverse = new StringBuilder(s).reverse().toString();
        for (int i = 0; i < keyStrArr.length; i++) {
            keyStrArr[i] = new StringBuilder(keyStrArr[i]).reverse().toString();
        }

        boolean isEqual = true;
        for (int i = 0; i < sReverse.length();) {
            boolean flg = false;// 文字列が部分一致するか
            for (int j = 0; j < keyStrArr.length; j++) {
                String partStr = "";
                if (i + keyStrArr[j].length() > sReverse.length()) {
                    partStr = sReverse.substring(i);
                } else {
                    partStr = sReverse.substring(i, i + keyStrArr[j].length());// iからの部分文字列
                }

                if (partStr.equals(keyStrArr[j])) {
                    // 部分一致したためroopを抜ける
                    i += keyStrArr[j].length();
                    flg = true;
                    break;
                }
            }

            // 文字列が一致しなかったためroopを抜ける
            if (!flg) {
                isEqual = false;
                break;
            }
        }

        System.out.println(isEqual ? "YES" : "NO");
    }
}
