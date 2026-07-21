import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        int K = Integer.parseInt(sc.next());
        sc.close();
        int mas[] = new int[100];
        int sum = 1;
        for (int i = 100; i > 0; i--) {
            if (A % i == 0 && B % i == 0) {
                mas[sum] = i;
                ++sum;
            }
        }
        System.out.println(mas[K]);

    }
}
