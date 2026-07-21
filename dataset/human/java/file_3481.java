import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        try (Scanner in = new Scanner(System.in)) {
            String X = in.next();
            String Y = in.next();

            if (X.equals(Y)) {
                System.out.println("=");
            } else if (X.charAt(0) > Y.charAt(0)) {
                System.out.println(">");
            } else {
                System.out.println("<");
            }
        }
    }
}
