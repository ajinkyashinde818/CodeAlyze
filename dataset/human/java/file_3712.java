import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String a = sc.next();
        String b = sc.next();

        sc.close();

        if (a.compareTo(b) < 0) {
            System.out.println("<");
        } else if (a.compareTo(b) > 0) {
            System.out.println(">");
        } else {
            System.out.println("=");
        }

    }

}
