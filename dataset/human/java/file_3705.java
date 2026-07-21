import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt(16);
        int y = scanner.nextInt(16);

        System.out.println((x == y) ? "=" : (x > y) ? ">" : "<");
    }
}
