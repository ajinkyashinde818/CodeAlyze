import java.util.*;

class Main {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        String s = sc.next();
        final String[] ss = {"dream", "dreamer", "erase", "eraser"};

        int r = s.length();
        while (r > 0) {

            boolean isFound = false;
            for (String x : ss) {
                if (r - x.length() < 0) {
                    // System.out.println(s);
                    continue;
                }
                String subs = s.substring((r - x.length()), r);
                // System.out.println(subs);
                if (x.equals(subs)) {
                    r -= x.length();
                    isFound = true;
                    break;
                }
            }
            if (!isFound) {
                System.out.println("NO");
                return;
            }
        }


        System.out.println("YES");
        sc.close();
    }
}
