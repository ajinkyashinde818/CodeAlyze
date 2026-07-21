import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;
import java.lang.Integer;
import java.lang.StringBuilder;
import java.lang.Math;

public class Main {

    public static int calc(int max, int target) {
        int cnt = 0;
        for (int i = 0; i <= max; i++) {
            for (int j = 0; j <= max; j++) {
                int sum = i + j;
                int k = target - sum;
                if (k <= max && k >= 0) {
                    //System.out.println(i + "," + j + "," + (target - sum));
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int K = in.nextInt();
        int S = in.nextInt();

        int result = calc(K, S);
        System.out.println(result);
    }
}
