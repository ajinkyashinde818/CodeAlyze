import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        if(n % 2 != 0) System.out.println(0);
        else{
            n /= 2;
            long ans = 0L;
            for (int i = 25; i > 0; i--) {
                long a = n / (long)Math.pow(5, i);
                ans += a;
            }
            System.out.println(ans);

        }
        sc.close();

    }

}
