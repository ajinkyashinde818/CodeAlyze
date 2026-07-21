import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextLong();
        long B = sc.nextLong();
        System.out.println(A*B/Main.d(A, B));
    }
    public static long d(long A,long B) {
        if (A<B) {
            return d(B,A);
        }
        if (B==0) {
            return A;
        }
        return d(A%B,B);
    }
}
