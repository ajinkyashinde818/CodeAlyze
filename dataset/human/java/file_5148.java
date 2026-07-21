import java.util.Scanner;

/**
 * AtCoder Beginner Contest 158
 * D - String Formation
 * https://atcoder.jp/contests/abc158/tasks/abc158_d
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder(sc.next());
        StringBuilder sbB = new StringBuilder();
        StringBuilder sbE = new StringBuilder();
        int q = sc.nextInt();

        boolean isAsc = true;
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 1) {
                isAsc = !isAsc;
            } else {
                int f = sc.nextInt();
                if (f == 1) {
                    if (isAsc) {
                        sbB.append(sc.next());
                    } else {
                        sbE.append(sc.next());
                    }
                } else {
                    if (isAsc) {
                        sbE.append(sc.next());
                    } else {
                        sbB.append(sc.next());
                    }
                }
            }
        }
        if (isAsc) {
            System.out.print(sbB.reverse().toString());
            System.out.print(sb.toString());
            System.out.print(sbE.toString());
        } else {
            System.out.print(sbE.reverse().toString());
            System.out.print(sb.reverse().toString());
            System.out.print(sbB.toString());
        }

    }
}
