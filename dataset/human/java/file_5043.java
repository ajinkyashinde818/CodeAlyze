import java.util.Scanner;

public class Main {
    static long q;
    static String s;
    static String t; //反転する文字列

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        q = sc.nextInt();
        t = "";

        StringBuffer sbs = new StringBuffer(s);
        StringBuffer sbt = new StringBuffer(t);
        StringBuffer tmp;

        for (int i = 0; i < q; i++) {
            if (sc.nextInt() == 1) {
                tmp = sbs;
                sbs = sbt;
                sbt = tmp;
            } else {
                if (sc.nextInt() == 1) {
                    sbt.append(sc.next());
                } else {
                    sbs.append(sc.next());
                }
            }
        }
        System.out.println(sbt.reverse().append(sbs));
    }
}
