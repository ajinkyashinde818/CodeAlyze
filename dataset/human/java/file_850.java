import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // ABC156A - Beginner

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int r = sc.nextInt();

        int rate = (n >= 10) ? r : r + (100 * (10 - n));

        System.out.println(rate);
    }
}
