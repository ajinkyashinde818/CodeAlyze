import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        new Main();
    }

    public Main() {
        Scanner sc = new Scanner(System.in);
        long a = Integer.parseInt(sc.next());
        long b = Integer.parseInt(sc.next());
        long r, x, tmp;

        x = a * b;
        if (a < b) {
            tmp = a;
            a = b;
            b = tmp;
        }

        r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }

        long lcm = x / b;
        System.out.println(lcm);
    }
}
