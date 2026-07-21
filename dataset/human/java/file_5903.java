import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();

        int[] a = new int[3];

        if (s.indexOf('a') == -1 ||
            s.indexOf('b') == -1 ||
            s.indexOf('c') == -1) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}
