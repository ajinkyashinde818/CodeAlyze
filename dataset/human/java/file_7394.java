import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String S = scanner.next();

        StringBuilder sb = new StringBuilder(S);

        S = sb.reverse().toString();

        // dream, dreamer, erase, eraser

        String[] keywords = {
                "dream", "dreamer", "erase", "eraser"
        };

        List<String> reversedKeywords = new ArrayList();

        for (String s : keywords) {
            reversedKeywords.add((new StringBuilder(s)).reverse().toString());
        }

        for (int i = 0; i < S.length();) {
            boolean found = false;
            for (String reversed : reversedKeywords) {
                if (S.startsWith(reversed, i)) {
                    i += reversed.length();
                    found = true;
                    break;
                }
            }
            if (!found) {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }
}
