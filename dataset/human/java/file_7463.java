import java.util.*;

public class Main {
    static String[] strs = {
        "maerd",
        "remaerd",
        "esare",
        "resare"
    };
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuffer s = new StringBuffer(100000);
        String s_in = sc.next();
        s.append(s_in);
        s.reverse();

        while (true) {
            boolean startsWithStr = false;
            for (String str: strs) {
                if (s.indexOf(str) == 0) {
                    startsWithStr = true;
                    s = s.delete(0, str.length());
                    break;
                }
            }
            if (!startsWithStr) {
                System.out.println("NO");
                break;
            }
            if (s.length() <= 0) {
                System.out.println("YES");
                break;
            }
        }
    }
}
