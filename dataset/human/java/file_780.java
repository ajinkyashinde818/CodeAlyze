import java.util.Scanner;

public class Main {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int r = Integer.parseInt(sc.next());

        int result = 0;
        if (n < 10) {
            result = r + (100 * (10 - n));
        } else {
            result = r;
        }

        System.out.println(result);

        sc.close();
    }
}
