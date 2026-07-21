import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String S = cin.next();

        S = S.replaceAll("eraser", "0");
        S = S.replaceAll("erase", "0");
        S = S.replaceAll("dreamer", "0");
        S = S.replaceAll("dream", "0");
        S = S.replaceAll("0", "");

        if (S.isEmpty()) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
