import java.util.*;
public class Main {
    public static void main(final String[] args){
        final Scanner sc = new Scanner(System.in);
        
        final int n = sc.nextInt();
        final int rate = sc.nextInt();
        sc.close();
        int res = rate;

        if(n < 10)
            res += 100 * (10 - n);
        // 出力
        System.out.println(res);
    }
}
