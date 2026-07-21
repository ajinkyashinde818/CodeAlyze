import java.util.*;
import javax.lang.model.util.ElementScanner6;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 入力
        int a = sc.nextInt();
        int b = sc.nextInt();

        long out = a;
        long a1 = a;
        long b1 = b;
        while (!(out % a == 0 && out % b == 0)) {
            out = a1 > b1 ? a1 : b1;
            if (a1 < out) {
                a1 += a;
            }
            if (b1 < out) {
                b1 += b;
            }
        }

        // 出力
        System.out.println(out);
    }
}
