import java.util.Scanner;

/**
 * String Formation
 * 
 * https://atcoder.jp/contests/abc158/tasks/abc158_d
 */
public class Main {

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) throws Exception {
        String S = sc.next();
        int Q = sc.nextInt();

        boolean order = true;
        StringBuilder prefix = new StringBuilder();
        StringBuilder suffix = new StringBuilder();

        for (int i = 0; i < Q; i++) {
            int T = sc.nextInt();

            if (T == 1) {
                order = !order;
            } else {
                int F = sc.nextInt();
                String C = sc.next();

                if ((F == 1 && order) || (F == 2 && !order)) {
                    prefix.append(C);
                } else {
                    suffix.append(C);
                }
            }
        }

        StringBuilder ans = new StringBuilder();
        ans.append(prefix.reverse());
        ans.append(S);
        ans.append(suffix);

        if (order) {
            System.out.println(ans.toString());
        } else {
            System.out.println(ans.reverse().toString());
        }
    }

}
