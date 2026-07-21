import java.util.Arrays;
import java.util.Scanner;

public class Main {
    void run() {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] aArr = new int[n];
        int[] bArr = new int[n];
        int[] cArr = new int[n - 1];

        for (int i = 0; i < n; i++) {
            aArr[i] = sc.nextInt() - 1;
        }
        for (int i = 0; i < n; i++) {
            bArr[i] = sc.nextInt();
        }
        for (int i = 0; i < n - 1; i++) {
            cArr[i] = sc.nextInt();
        }

        int sum = 0;
        sum += bArr[aArr[0]];
        for (int i = 1; i < n; i++) {
            sum += bArr[aArr[i]];
            boolean hoge = aArr[i - 1] + 1 == aArr[i];
            if (hoge) {
//                System.out.println(i + " x");
                sum += cArr[aArr[i] - 1];
            }
        }

        // write your code
        System.out.println(sum);
    }

    void debug(Object... os) {
        System.err.println(Arrays.deepToString(os));
    }

    public static void main(String[] args) {
        new Main().run();
    }
}
