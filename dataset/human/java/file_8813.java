import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();;
        int b = sc.nextInt();;
        int c = sc.nextInt();
        sc.close();
        Integer[] divisors = new Integer[Math.max(a, b)];
        Arrays.fill(divisors, 0);
        for (int i = 1; i <= Math.max(a, b); i++) {
            if (a % i == 0 && b % i == 0) divisors[i - 1] = i;
        }
        Arrays.sort(divisors, Comparator.reverseOrder());
        System.out.println(divisors[c - 1]);
    }
}
