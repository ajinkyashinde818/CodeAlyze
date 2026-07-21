import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int base = 1;
        while (base * 2 <= n) {
            base *= 2;
        }
        System.out.println(base);
    }
}
