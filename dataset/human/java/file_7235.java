import java.util.Scanner;

public class Main {
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        long k = scanner.nextLong();
        int n = scanner.nextInt();
        long [] d = new long[n];
        for (int i = 0; i < n; ++i) {
            d[i] = scanner.nextLong();
        }
        long ans = k;
        for (int i = 0; i < n; ++i) {
            int left = (i - 1 + n) % n;
            int right = (i + 1) % n;
            long dLeft = i == 0
                    ? k - d[n - 1] + d[i]
                    : Math.abs(d[left] - d[i]);
            long dRight = i == n - 1
                    ? k - d[i] + d[right]
                    : Math.abs(d[right] - d[i]);
            long current = k - Math.max(dLeft, dRight);
//            System.out.println("i: " + i);
//            System.out.println("left: " + left + " dleft: " + dLeft);
//            System.out.println("right: " + right + " dright: " + dRight);
//            System.out.println("current: " + current);
            ans = Math.min(ans, current);
        }
        System.out.println(ans);
    }
}
