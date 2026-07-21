import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), r = sc.nextInt();
        
        if (n <= 10) {
            int x = 100 * (10 - n);
            System.out.println(r + x);
            return;
        }
        System.out.println(r);
    }
}
