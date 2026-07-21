import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long n = N;
        sc.close();

        int maxCount = (int) Math.sqrt(N);
        int[] z = new int[maxCount + 3];

        int count = 2;
        while (n != 1) {
            if (count > maxCount) {
                z[maxCount + 1]++;
                break;
            }
            while (n % count == 0) {
                n /= count;
                z[count]++;
            }
            count++;
        }

        int ans = 0;
        for (int i = 0; i <= maxCount + 1; i++) {
            int cnt = 1;
            while (z[i] - cnt >= 0) {
                z[i] -= cnt;
                cnt++;
                ans++;
            }
        }

        System.out.println(ans);
    }
}
