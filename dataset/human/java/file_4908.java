import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();

        if (N % 2 == 1) {
            System.out.println(0);
            return;
        }

        long res = 0;
        N /= 2;
        while (N > 0) {
            res += N / 5;
            N /= 5;
        }
        System.out.println(res);
    }
}
