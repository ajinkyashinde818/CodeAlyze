import java.util.Scanner;

public class Main {
    static char[] c;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder(sc.next());
        sb.reverse();
        c = sb.toString().toCharArray();
        String str = "";
        boolean ok = true;
        for (int i = 0; i < c.length; i++) {
            if (str.equals("dream") || str.equals("dreamer")
            || str.equals("erase") || str.equals("eraser")) {
                str = "" + c[i];
            } else if (str.length() > 7) {
                ok = false;
                break;
            } else {
                str = c[i] + str;
            }
        }
        if (str.equals("dream") || str.equals("dreamer")
                || str.equals("erase") || str.equals("eraser")) {
        } else {
            ok = false;
        }
        System.out.println(ok?"YES":"NO");
    }
}
