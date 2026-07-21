import java.util.*;

class Main {
    static String[] strs = {
        "dream",
        "dreamer",
        "erase",
        "eraser"
    };
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        
        while (true) {
            boolean endsWithStr = false;
            for (String str: strs) {
                if (s.endsWith(str)) {
                    endsWithStr = true;
                    s = s.substring(0, s.length() - str.length());
                    break;
                }
            }
            if (!endsWithStr) {
                System.out.println("NO");
                break;
            }
            if (s.length() == 0) {
                System.out.println("YES");
                break;
            }
        }
        sc.close();
    }
}
