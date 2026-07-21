import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        /** 解毒入り美味しくないクッキー */
        int a = sc.nextInt();

        /** 解毒入り美味しいクッキー */
        int b = sc.nextInt();

        /** 毒入り美味しいクッキー */
        int c = sc.nextInt();

        int sum = 0;

        // まずは毒入りクッキーと解毒入りのクッキー交互に食べる
        while (b != 0 && c != 0) {
            sum += 2;
            b--;
            c--;
        }

        /**
         * どちらか一方がなくなったら 毒入りが余っている場合は、美味しくないクッキーと一緒に食べる
         * 解毒入り美味しくないクッキーが余っていたら、あまりを合計に追加して終了
         */
        if (b > 0) {
            sum += b;
            System.out.println(sum);
            return;
        } else if (c > 0) {
            while (a != 0 && c != 0) {
                sum += 1;
                a--;
                c--;
            }

            // 最後に毒入りで終了するのはありなので 余っている場合は合計にプラスする
            if (c > 0) {
                sum++;
            }

            System.out.println(sum);

        } else {
            // どちらも残っていない(美味しいクッキーがもうない)場合は終了
            System.out.println(sum);
        }
    }
}
