import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x = sc.next();
        String y = sc.next();
        int a = Integer.parseInt(x, 16);
        int b = Integer.parseInt(y, 16);
        if (a == b) {
            System.out.println("=");
        } else if (a < b) {
            System.out.println("<");
        } else {
            System.out.println(">");
        }

    }
}
