import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        long A = input.nextInt();
        long B = input.nextInt();

        System.out.println(lcm(A,B));
    }

    public static long gcd(long A, long B) {
        while (B > 0) {
            long tmp = B;
            B = A % B;
            A = tmp;
        }
        return A;
    }

    public static long lcm(long A, long B) {
        return (A * B) / gcd(A,B);
    }
}
