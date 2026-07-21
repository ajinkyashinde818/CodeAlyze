import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);


    public static void main(String[] args) {
        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        for (int bit = 0; bit < 1 << d; bit++) {
            int sum = 0;
            int count = 0;
            for (int i = 0; i < d; i++) {
                if ((bit & 1 << i) > 0) {
                    sum += 100 * (i + 1) * p[i] + c[i];
                    count += p[i];
                }
            }
            if (sum < g) {
                for (int j = d - 1; j >= 0; j--) {
                    if ((bit & 1 << j) > 0) continue;
                    for (int k = 0; k < p[j]; k++) {
                        if (sum >= g) {
                            break;
                        }
                        sum += 100 * (j + 1);
                        count++;
                    }
                }
            }
            result = Math.min(result, count);
        }
        System.out.println(result);
    }

}
