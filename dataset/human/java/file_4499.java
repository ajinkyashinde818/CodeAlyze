import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int A = scan.nextInt();
        int B = scan.nextInt();
        int C = scan.nextInt();
        int Ans = 0;

        if( A + B >= C ) {
            Ans = B + C;
        } else {
            Ans = A + B + 1 + B;
        }

        System.out.println(Ans);
        scan.close();
    }
}
