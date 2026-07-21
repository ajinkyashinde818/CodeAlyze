import java.util.Scanner;

public class Main {
    public static void main(final String[] args) {
        final Scanner sc = new Scanner(System.in);
        final String S = sc.next();
        String[] ts = {"eraser", "erase", "dreamer", "dream"};
        System.out.println(judgeSEqualT(S, ts));
        sc.close();
    }

    public static String judgeSEqualT(String target, String[] strs) {
        for (String str : strs) {
            target = target.replace(str, "");
            if (target.length() == 0) {
                return "YES";
            } else {
                continue;
            }
        }
        return "NO";
    }
}
