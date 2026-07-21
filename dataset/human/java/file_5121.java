import java.util.Scanner;

public class Main {

    public static void main(String args[]) {

        // 入力
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int q = Integer.parseInt(sc.next());

        boolean isReverse = false;
        StringBuffer head = new StringBuffer();
        StringBuffer foot = new StringBuffer();
        for (int i = 0; i < q; i++) {
            String query = sc.next();
            if ("2".equals(query)) {
                String func = sc.next();
                if (("1".equals(func) && !isReverse) || ("2".equals(func) && isReverse)) {
                    head.insert(0, sc.next());
                } else {
                    foot.append(sc.next());
                }
            } else {
                isReverse = !isReverse;
            }
        }

        StringBuffer result = new StringBuffer(head + s + foot);

        if (isReverse) {
            result.reverse();
        }

        // 出力
        System.out.println(result.toString());
        sc.close();
    }
}
