import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int x = scan.nextInt();
        if (x >= 1200) {
            System.out.println("ARC");
        } else {
            System.out.println("ABC");
        }
    }
}
