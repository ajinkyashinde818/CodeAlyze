import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = Integer.parseInt(scanner.next());

        scanner.close();

        if (X >= 1200) {
            System.out.println("ARC");
        } else {
            System.out.println("ABC");
        }
    }
}
