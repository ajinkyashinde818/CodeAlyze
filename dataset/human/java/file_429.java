import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        int n, r;

        n = cin.nextInt();
        r = cin.nextInt();

        if (n >= 10) {
            System.out.println(r);
        } else {
            System.out.println(r + 100 * (10 - n));
        }
    }
}
