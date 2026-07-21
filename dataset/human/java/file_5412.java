import java.util.Scanner;

public class Main {

    public Main() {
    }

    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);
        new Main().run();
    }

    private void run() {
        int x = sc.nextInt();
        if (x < 1200) {
            System.out.println("ABC");
        } else {
            System.out.println("ARC");
        }
    }
}
