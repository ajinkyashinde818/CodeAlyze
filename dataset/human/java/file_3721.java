import java.util.Scanner;

public class Main {
    static String X;
    static String Y;

    private static void init() {
        Scanner scanner = new Scanner(System.in);
        X = scanner.next();
        Y = scanner.next();
        scanner.close();
    }


    public static void main(String args[]) {
        init();
        if(0 < X.compareTo(Y)) {
            System.out.println(">");
        } else if(0 > X.compareTo(Y)) {
            System.out.println("<");
        } else {
            System.out.println("=");
        }
    }
}
