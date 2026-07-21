import java.util.*;

public class Main {
    public static void main(String[] args) {
        final Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int mn = Math.min(b, c);
        b -= mn;
        c -= mn;
        int ans = mn * 2;
        mn = Math.min(a+1, c);
        System.out.println(ans+mn+b);
        sc.close();
    }
}
