import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    int MOD = (int)998244353;

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        char s = sc.next().charAt(0);
        char t = sc.next().charAt(0);

        if (s == t) {
            System.out.println("=");
        } else if (s < t) {
            System.out.println("<");
        } else {
            System.out.println(">");
        }

    }
}
