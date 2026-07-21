import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        S = S.replaceAll("eraser", "-");
        S = S.replaceAll("erase", "-");
        S = S.replaceAll("dreamer", "-");
        S = S.replaceAll("dream", "-");
        S = S.replaceAll("-", "");

        PrintWriter out = new PrintWriter(System.out);

        if (S.length() == 0) {
            out.println("YES");
        } else {
            out.println("NO");
        }

        sc.close();
        out.flush();
    }
}
