import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            String S = in.next();

            String[] s = new String[] { "dream", "dreamer", "erase", "eraser", };

            for (int index = S.length(); index > 0;) {
                String match = find(S, index, s);

                if (match == null) {
                    System.out.println("NO");
                    return;
                }

                index -= match.length();
            }

            System.out.println("YES");
        }
    }

    private static String find(String S, int index, String[] s) {
        for (String dream : s) {
            if (S.substring(0, index).endsWith(dream)) {
                return dream;
            }
        }
        return null;
    }
}
