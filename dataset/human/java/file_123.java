import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        int minusCount = 0;
        long min = Long.MAX_VALUE;
        boolean hasZero = false;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
            if (a[i] == 0) {
                hasZero = true;
            }
            if (a[i] < 0) {
                minusCount++;
                min = Math.min(min, -a[i]);
            } else {
                min = Math.min(min, a[i]);
            }
        }
        long total = 0;
        for (int i = 0; i < n; i++) {
            if(a[i] >= 0) total += a[i];
            else total -= a[i];
        }
        if(!hasZero && minusCount % 2 != 0) total -= (min * 2);
        System.out.println(total);
    }
}
