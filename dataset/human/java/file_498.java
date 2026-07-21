import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        final Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        final int n = in.nextInt();
        final int r = in.nextInt();
        if (n >= 10) {
            System.out.println(r);
        } else {
            System.out.println(100 * (10 - n) + r);
        }
    }
}
