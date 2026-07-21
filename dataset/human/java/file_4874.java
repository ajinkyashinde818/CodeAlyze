import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long ans = 0;
        if (N%2==0) {
            N/=2;
            long tmp =1;
            for (int i=0;i<27;i++) {
                tmp*=5;
                ans += N/tmp;
            }
        }
        System.out.println(ans);
    }
}
