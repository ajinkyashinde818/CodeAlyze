import java.util.Scanner;

public class Main {
    public static void main(String [] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();
        if (n >= 10) {
            System.out.println(r);
        }   else {
            int x = r + 100 * (10 - n);
            System.out.println(x);
        }
    }
}
