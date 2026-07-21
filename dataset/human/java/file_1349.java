import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int N = in.nextInt();
            int M = in.nextInt();
            int[][] A = new int[N][N];
            for (int i = 0; i < N; i++) {
                String line = in.next();
                for (int j = 0; j < N; j++) {
                    A[i][j] = line.charAt(j) == '.' ? 0 : 1;
                }
            }
            int[][] B = new int[M][M];
            for (int i = 0; i < M; i++) {
                String line = in.next();
                for (int j = 0; j < M; j++) {
                    B[i][j] = line.charAt(j) == '.' ? 0 : 1;
                }
            }

            for (int r = 0; r + M <= N; r++) {
                for (int c = 0; c + M <= N; c++) {

                    boolean match = true;
                    drLoop: for (int dr = 0; dr < M; dr++) {
                        for (int dc = 0; dc < M; dc++) {
                            if (B[dr][dc] != A[r + dr][c + dc]) {
                                match = false;
                                break drLoop;
                            }
                        }
                    }

                    if (match) {
                        System.out.println("Yes");
                        return;
                    }

                }
            }
            System.out.println("No");
        }
    }
}
