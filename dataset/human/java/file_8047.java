import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int aa = a;
        int bb = b;

        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        System.out.print((long) aa/a*bb );
    }
}
