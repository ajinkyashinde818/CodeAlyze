import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        int X = scanner.nextInt();
        int[][] books = new int[N][M + 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M + 1; j++) {
                books[i][j] = scanner.nextInt();
            }
        }
        scanner.close();
        int max = 12345678;

        Loop: for (int i = 0; i < (1 << N); i++) {
            int[] summmary = new int[M + 1];
            for (int j = 0; j < N; j++) {
                if ((1 & i >> j) == 1) {
                    for (int index = 0; index < M + 1; index++) {
                        summmary[index] += books[j][index];
                    }
                }
            }
            for (int j = 1; j < M + 1; j++) {
                if (summmary[j] < X) {
                    continue Loop;
                }
            }
            if (max > summmary[0]) {
                max = summmary[0];
            }
        }

        if (max != 12345678) {
            System.out.println(max);
        } else {
            System.out.println(-1);
        }

    }
}
