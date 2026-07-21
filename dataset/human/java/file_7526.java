import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder N = new StringBuilder(sc.nextLine());
        sc.close();

        String[] match = { "dream", "dreamer", "erase", "eraser" };

        boolean next = true;
        int length = N.length();
        while (next && length > 0) {
            next = false;
            for (int i = 0; i < match.length; i++) {
                int lastIndex = N.lastIndexOf(match[i]);
                if (lastIndex>=0 && lastIndex + match[i].length() == length) {
                    N.setLength(length - match[i].length());
                    next = true;
                    length = N.length();
                    break;
                }
            }
        }
        if (next) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
