import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner std = new Scanner(System.in);
        int a = std.nextInt();
        int b = std.nextInt();
        int c = std.nextInt();
        if (a + b + 1 >= c) {
            long ans = b + c;
            System.out.println(ans);
        } else {
            long ans = a + b + 1 + b;
            System.out.println(ans);
        }
    }
}
