import java.util.*;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        String[] a = new String[n];
        String[] b = new String[m];
        Arrays.setAll(a, i -> sc.next());
        Arrays.setAll(b, i -> sc.next());
        sc.close();

        // 主処理
        boolean judge = false;
        for (int i = 0; i <= n - m; i++) {
            int startIndex = 0;
            int index = a[i].indexOf(b[0], startIndex);
            while (0 <= index && index <= n - m) {
                boolean isSame = true;
                for (int j = 1; j < m; j++) {
                    if (index != a[i + j].indexOf(b[j], startIndex)) {
                        isSame = false;
                        break;
                    }
                }
                if (isSame) {
                    judge = true;
                    break;
                } else if (index < n - 1) {
                    startIndex = index + 1;
                    index = a[i].indexOf(b[0], startIndex);
                }
            }
        }
        String result = judge ? "Yes" : "No";

        // 出力
        System.out.println(result);
    }
}
