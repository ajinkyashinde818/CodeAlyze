import java.util.Objects;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String S = s.next();
        int Q = Integer.parseInt(s.next());
        StringBuilder origin = new StringBuilder(S);
        StringBuilder front = new StringBuilder();
        StringBuilder back = new StringBuilder();
        /**
         * 4 2 1 p 1 2 2 c 1
         */
        /**
         * 123 先頭にp追加 p123 反転 321p 末尾にc追加 321pc 反転 cp123 先頭にa追加 acp123 末尾にb追加 acp123b
         */
        // 反転しているかどうか
        // 反転していない場合の先頭追加、末尾追加
        // 反転している場合の先頭追加、末尾追加
        boolean normal = true;
        for (int i = 0; i < Q; i++) {
            String type = s.next();
            // 反転
            if (Objects.equals(type, "1")) {
                normal = !normal;
                continue;
            }
            // 追加処理
            String F = s.next();
            String C = s.next();
            if (Objects.equals(F, "1")) {
                // 先頭追加処理
                if (normal) {
                    front.append(C);
                } else {
                    back.append(C);
                }
            } else {
                // 末尾追加処理
                if (normal) {
                    back.append(C);
                } else {
                    front.append(C);
                }
            }
        }
        // 表示処理
        if (normal) {
            System.out.print(front.reverse());
            System.out.print(origin);
            System.out.println(back);
        }else{
            System.out.print(back.reverse());
            System.out.print(origin.reverse());
            System.out.println(front);
        }
    }
}
