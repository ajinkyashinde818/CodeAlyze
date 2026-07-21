import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        final int N = sc.nextInt();
        final int R = sc.nextInt();

        System.out.println(N >= 10 ? R : R + 100 * (10 - N));
    }
}
