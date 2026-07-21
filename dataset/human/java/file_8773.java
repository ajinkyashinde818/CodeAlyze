import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        int count = 0;
        for (int i = Math.min(A,B); i > 0; i--) {
            if (A % i == 0 && B % i  == 0) {
                count++;
            }
            if (count == K) {
                System.out.println(i);
                break;
            }
        }
    }
}
