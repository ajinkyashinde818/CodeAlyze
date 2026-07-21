import java.util.Scanner;

public class Main {
    public static void main(String[] c) {
        Scanner scan = new Scanner(System.in);
        String[] t = scan.nextLine().split("\\s");
        int n = Integer.valueOf(t[0]);
        int r = Integer.valueOf(t[1]);

        if (n >= 10)  {
            System.out.println(r);
        } else {
            int num = 100 * (10 - n);
            System.out.println(r + num);
        }
    }
}
