import java.lang.reflect.Array;
import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();

        // 主処理
        char[] charS = s.toCharArray();
        Arrays.sort(charS);
        char[] charT = t.toCharArray();
        Arrays.sort(charT);

        String s2 = "";
        for (char c : charS) {
            s2 += c;
        }
        String t2 = "";
        for (char c : charT) {
            t2 = c + t2;
        }

        String[] array = new String[] { s2, t2 };
        Arrays.sort(array);

        boolean judge = s2.equals(array[0]);
        String result = judge && !s.equals(t) ? "Yes" : "No";

        // 出力
        System.out.println(result);
        sc.close();
    }
}
