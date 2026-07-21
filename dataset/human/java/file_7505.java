import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        String[] strings = new String[]{
            "dream",
            "dreamer",
            "erase",
            "eraser"
        };

        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        int allLength = S.length();
        int strLength = 0;
        while (true) {
            for (int i = 0; i < strings.length; i++) {
                int restLength = allLength - strings[i].length();
                if (restLength < 0) {
                    continue;
                }
                if ((S.substring(restLength, allLength)).equals(strings[i])) {
                    strLength = strings[i].length();
                    break;
                }
            }
            if (strLength == 0) {
                System.out.println("NO");
                System.exit(0);
            }
            allLength -= strLength;
            if (allLength == 0) {
                System.out.println("YES");
                System.exit(0);
            }
            strLength = 0;
        }
    }
}
