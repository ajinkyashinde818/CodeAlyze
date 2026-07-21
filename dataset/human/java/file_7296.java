import java.util.Scanner;

public class Main {

    static String[] strs = { "eraser", "erase", "dreamer", "dream" };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        sc.close();
        int idx = S.length();

        while (true) {
            boolean endsWithStr = false;
            for (String str : strs) {
                if (idx - str.length() >= 0 && S.indexOf(str, idx - str.length()) == idx - str.length()) {
                    idx -= str.length();
                    endsWithStr = true;
                    break;
                }
            }
            if (!endsWithStr) {
                System.out.println("NO");
                break;
            }
            if (idx == 0) {
                System.out.println("YES");
                break;
            }
        }
    }
}
