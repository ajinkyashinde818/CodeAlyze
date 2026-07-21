import java.util.*;

public class Main {
    //K-th Common Divisor
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt(), k = sc.nextInt();
        System.out.println(helper(a, b, k));
        sc.close();
    }

    public static int helper(int a, int b, int k) {
        int count = 0;
        for (int i = Math.min(a, b); i >= 1; i--) {
            if (a % i == 0 && b % i == 0) count++;
            if (count == k) return i;
        }
        return 0;
    }
}
