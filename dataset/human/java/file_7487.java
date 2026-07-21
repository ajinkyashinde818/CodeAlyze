import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            String s = sc.next();
            boolean prevIsDream = false;
            boolean prevIsErase = false;
            int idx = 0;

            while (idx < s.length()) {
                if (s.startsWith("erase", idx)) {
                    idx += 5;
                    prevIsErase = true;
                    prevIsDream = false;
                } else if (s.startsWith("dream", idx)) {
                    idx += 5;
                    prevIsErase = false;
                    prevIsDream = true;
                } else if (s.startsWith("er", idx) && prevIsDream) {
                    idx += 2;
                    prevIsErase = false;
                    prevIsDream = false;
                } else if (s.startsWith("r", idx) && prevIsErase) {
                    idx++;
                    prevIsErase = false;
                    prevIsDream = false;
                } else {
                    break;
                }
            }

            if (idx == s.length()) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}
