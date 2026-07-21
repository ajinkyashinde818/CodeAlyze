import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int tmp = 0;
        if (A < B) {
            tmp = B;
            B = A;
            A = tmp;
        }
        long num = 0;
        for (int b = 1; b <= B; b++){
            num = num + A;
            if (num % B == 0) {
                System.out.println(num);
                System.exit(0);
            }
        }
    }
}
