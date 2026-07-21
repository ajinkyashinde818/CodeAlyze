import java.util.*;
import javax.lang.model.util.ElementScanner6;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 入力
        int n = sc.nextInt();
        int r = sc.nextInt();

        // 処理
        int out = 0;
        if (n >= 10){
            out = r;
        } else {
            out = r + (100 * (10 - n));
        }

        // 出力
        System.out.println(out);
    }

}
