import java.util.*;

public class Main {
    public static void main(String[] args){
        long N;
        Scanner sc = new Scanner(System.in);
        N = sc.nextLong();
        if (N % 2 == 1) System.out.print("0\n");
        else {
            long ans = 0;
            long a = 5;
            while (2*a <= N) {
                ans += N/(2*a);
                a *= 5;
            }
            System.out.println(ans);
        }
    }
}
