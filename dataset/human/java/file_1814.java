import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];

        for (int i = 0 ; i < d ; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        int ans = Integer.MAX_VALUE;
        for (int mask = 0; mask < 1 << d; mask++) {
            int sum = 0;
            int cnt = 0;
            int rest_max = -1;
            for (int i = 0; i < d ; i++) {
                if ((mask >> i & 1) == 1) {
                    sum += p[i] * (i + 1) * 100 + c[i];
                    cnt += p[i];
                } else {
                    rest_max = i;
                }
            }
            if (rest_max >= 0) {
                for (int i = 0 ; i < p[rest_max]; i++) {
                    if (sum >= g) {
                        break;
                    } else {
                        sum += (rest_max + 1) * 100;
                        cnt++;
                    }
                }
            }
            if (sum >= g) {
                ans = Math.min(cnt, ans);
            }
        }

        System.out.println(ans);
    }

}
