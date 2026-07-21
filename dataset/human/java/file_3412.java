import java.util.Scanner;

/**
 * Created by lyc on 2017/10/12.
 */
class Main{
    public static void main(String[] strings) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();

        if (s.indexOf("9") != -1) {
            System.out.print("Yes");
        } else {
            System.out.print("No");
        }

    }
}
