import java.util.*;
import java.lang.*;


public class Main {
    static int cmp[] = new int[10];
    static int d;
    static int g;
    static int p[];
    static int c[];
    static int min = 100000;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        d = sc.nextInt();
        g = sc.nextInt();
        p = new int[d];
        c = new int[d];
        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        func(0);
        System.out.println(min);
    }
    static void func (int x) {
        if (x == d) {
            int sum = 0;
            int count = 0;
            for (int i = 0; i <= d - 1; i++) {
                sum += cmp[i] * (100 * (i + 1) * p[i]);
                sum += cmp[i] * c[i];
                count += cmp[i] * p[i];
            }
            for (int i = d - 1; i >= 0 && sum < g; i--) {
                if (cmp[i] == 0 && p[i] > 0) {
                    int v = 100 * (i + 1);
                    int num = Math.min(((g - sum + v-1) / v), p[i]);
                    sum += num*v;
                    count += num;
                }
            }
            if (sum >= g) {
                min = Math.min(min, count);
            }
            return;
        }
        cmp[x] = 1;
        func(x + 1);
        cmp[x] = 0;
        func(x + 1);
    }
}
