import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String t = sc.next();
        char[] sL = s.toCharArray();
        char[] tL = t.toCharArray();
        Arrays.sort(sL);
        Arrays.sort(tL);

        String ss = new String(sL);
        String tt = new String(tL);
        String ts = new StringBuffer(tt).reverse().toString();
        if (ss.compareTo(ts) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

}
