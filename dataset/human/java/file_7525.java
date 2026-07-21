import java.io.ByteArrayInputStream;
import java.util.Scanner;

public class Main
{
    private static boolean strcmp(String s, int pos, String other) {
        if (pos >= other.length()) {
            int len = other.length();
            for (int i = 0; i < len; i++) {
                if (s.charAt(pos - i - 1) != other.charAt(len - i - 1)) {
                    return false;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int pos = s.length();
        while (pos > 0) {
            if (strcmp(s, pos, "dream")) {
                pos -= 5;
            }
            else if (strcmp(s, pos, "dreamer")) {
                pos -= 7;
            }
            else if (strcmp(s, pos, "erase")) {
                pos -= 5;
            }
            else if (strcmp(s, pos, "eraser")) {
                pos -= 6;
            }
            else {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
