import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // ABC148C - Snack

        Scanner sc = new Scanner(System.in);

        long a = (long)sc.nextInt();
        long b = (long)sc.nextInt();

        long x = 0;
        
        for (int i = 1; i <= b; i++) {
            x = a * i;
            if (x % b == 0) {
                break;
            }
        }
        
        System.out.println(x);
    }
}
