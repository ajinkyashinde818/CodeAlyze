import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        long ans = 0;
        for (int i = 2; i < Math.sqrt(n) + 1; i++) {
            int e = 0;
            while(n % i == 0){
                e++;
                n /= i;
            }
            for (int j = 1; j <= e; j++) {
                ans++;
                e -= j;
            }
        }
        if(1 < n) ans += 1;
        System.out.println(ans);
        sc.close();

    }

}
