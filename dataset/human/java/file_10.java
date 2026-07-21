import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int m = (int) Math.sqrt(1 + 8 * N);

        if (m * m != 1 + 8 * N) {
            System.out.println("No");
            return;
        }

        if (1 + m % 2 == 1) {
            System.out.println("No");
            return;
        }

        System.out.println("Yes");

        int k = (1 + m) / 2;
        System.out.println(k);

        int[][] mattix = new int[k][k];

        int cnt = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i >= j) continue;
                mattix[i][j] = cnt;
                mattix[j][i] = cnt;
                cnt++;
            }
        }

        for (int i = 0; i < k; i++) {
            System.out.print(k-1);
            System.out.print(" ");
            int printedCnt = 0;

            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                System.out.print(mattix[i][j]);
                printedCnt++;

                if (printedCnt != k - 1) {
                    System.out.print(" ");
                }

            }

            System.out.print("\n");
        }
    }
}
