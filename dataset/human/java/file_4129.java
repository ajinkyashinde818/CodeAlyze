import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int[][] result = new int[3][N];
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < N; i++) {
                if (j == 2 && i == N - 1) break;
                result[j][i] = Integer.parseInt(sc.next());
            }
        }

        int answer = 0;
        int preIndex = -1;
        for (int i = 0; i < N; i++) {
            answer += result[1][result[0][i] - 1];
            if ((result[0][i] - preIndex) == 1) {
                answer += result[2][preIndex - 1];
            }
            preIndex = result[0][i];
        }

        System.out.println(answer);
    }
}
