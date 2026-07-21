import java.util.Scanner;

public class Main {

    private static int taskOne(int n, int k) {
        return 0;
    }

    private static int taskTwo() {
        return 0;
    }

    private static int taskThree() {
        return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();

        if (n >= 10) {
            System.out.println(r);
        } else {
            System.out.println(r + 100 * (10 - n));
        }
    }
}
