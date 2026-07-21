import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();

        s = s.replace("eraser", "");
        s = s.replace("erase", "");
        s = s.replace("dreamer", "");
        s = s.replace("dream", "");

        if (s.length() > 0) {
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}
