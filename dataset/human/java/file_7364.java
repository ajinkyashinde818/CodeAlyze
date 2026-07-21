import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();

        String[] patternList = new String[] {"dreamer", "dream", "eraser", "erase"};
        for (int i = 0; i < 4; ++i) {
            patternList[i] = new StringBuilder(patternList[i]).reverse().toString();
        }

        S = new StringBuilder(S).reverse().toString();

        for (int i= 0; i< S.length();) {
            boolean exists = false;
            for (int k = 0; k < 4; k++) {
                if (i + patternList[k].length() - 1 >= S.length()) {
                    continue;
                }
                if (S.substring(i, i + patternList[k].length()).equals(patternList[k])) {
                    exists = true;
                    i += patternList[k].length();
                    break;
                }
            }
            if (!exists) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
