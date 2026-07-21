import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 0;
        int minAbs = Integer.MAX_VALUE;
        long sum = 0L;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int abs = Math.abs(a);
            sum += (long)abs;
            if(a < 0) cnt++;
            if(abs < minAbs){
                minAbs = abs;
            }
        }
        if(0 < minAbs && cnt % 2 != 0){
            sum -= 2 * minAbs;
        }
        System.out.println(sum);
        sc.close();

    }

}
