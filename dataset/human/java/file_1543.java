import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = scan.nextInt();
        int M = scan.nextInt();
        char[][] A = new char[N][N];
        for (int i = 0; i < N; i++) {
            String t = scan.next();
            A[i] = t.toCharArray();
        }
        char[][] B = new char[M][M];
        for (int i = 0; i < M; i++) {
            String t = scan.next();
            B[i] = t.toCharArray();
        }

        boolean answer = false;
        for (int i = 0; i < N - M + 1 && !answer; i++) {
            for (int j = 0; j < N - M + 1 && !answer; j++) {
                boolean found = true;
                for (int k = 0; k < M; k++) {
                    for (int l = 0; l < M; l++) {
                        if (A[i+k][j+l] != B[k][l]) {
                            found = false;
                            break;
                        }
                    }
                    if (!found) {
                        break;
                    }
                }
                if (found) {
                    answer = true;
                    break;
                }
            }
        }
        System.out.println(answer ? "Yes" : "No");
    }
}
