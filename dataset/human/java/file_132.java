import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static long a[] = new long[100010];
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int res = 0;
        boolean flag = false;
        long sum = 0;
        for(int i = 1; i <= n; i++) {
            a[i] = cin.nextLong();
            if(a[i] < 0) {
                res++;
                a[i] = -a[i];
            }
            if(a[i] == 0) flag = true;
            sum += a[i];
        }
        if(flag){
            System.out.println(sum);
            return;
        }
        Arrays.sort(a, 1, n + 1);
        if(res % 2 == 1){
            System.out.println(sum - 2 * a[1]);
        }
        else System.out.println(sum);
    }
}
