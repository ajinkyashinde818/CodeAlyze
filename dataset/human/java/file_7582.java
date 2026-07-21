import java.util.*;
import java.util.regex.*;

class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        final String S = sc.next();
        sc.close();

        if (Pattern.matches("^(dream|dreamer|erase|eraser)*", S)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
