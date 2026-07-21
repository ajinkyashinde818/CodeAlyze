import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long n = sc.nextLong();

        long ans = 0;
        
        if (n % 2 == 1) {
        System.out.println(ans);
        return;
        }

        long num = 10;
        for (int i = 0; i < 100; i++) {
            if (n >= num) {
                ans += n / num;
                num = num * 5; 
            } else {
                break;
            }
        }
        System.out.println(ans);
    }
}
