import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        int Q = sc.nextInt();
        StringBuilder sbL = new StringBuilder("");
        StringBuilder sbR = new StringBuilder("");
        boolean nowReverse = false;
        for (int i = 0; i < Q; i++) {
            int T = sc.nextInt();
            if (T == 1) {
                nowReverse = nowReverse? false : true;
            } else {
                int F = sc.nextInt();
                String C = sc.next();
                if (F == 1) {
                    if (nowReverse) {
                        sbR.append(C);
                    } else {
                        sbL.append(C);
                    }
                } else {
                    if (nowReverse) {
                        sbL.append(C);
                    } else {
                        sbR.append(C);
                    }
                }
            }
        }
        String L = sbL.toString();
        String R = sbR.toString();
        S = reverseString(L) + S + R;
        System.out.println(nowReverse? reverseString(S) : S);
    }

    public static String reverseString(String S) {
        StringBuffer str = new StringBuffer(S);
        return str.reverse().toString();
    }
}
