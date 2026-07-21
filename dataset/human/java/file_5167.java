import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuffer ans = new StringBuffer(sc.next());
        int q = sc.nextInt();
        int t = 0;
        int f = 0;
        int tmp = 0;
        StringBuffer forw = new StringBuffer();
        StringBuffer back = new StringBuffer();
        String c = "";
        for (int i = 0; i < q; i++) {
            tmp = sc.nextInt();
            if (tmp == 1) {
                t++;
            } else {
                f = sc.nextInt();
                c = sc.next();
                if ((t % 2 == 1 && f == 2) || (t % 2 == 0 && f == 1)) {
                    forw.append(c);
                } else {
                    back.append(c);
                }
            }
        }
        ans = forw.reverse().append(ans).append(back);
        if (t % 2 == 1)
            ans.reverse();
        System.out.println(ans.toString());
        sc.close();
    }
}
