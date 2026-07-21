import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String X = sc.next();
        String Y = sc.next();
        int x = X.codePointAt(0);
        int y = Y.codePointAt(0);
        if (x == y) {
            System.out.println("=");
        }
        if (x > y) {
            System.out.println(">");
        }
        if (x < y) {
            System.out.println("<");
        }
    }
}
