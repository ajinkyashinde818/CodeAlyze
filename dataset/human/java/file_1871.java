import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 難易度数
        int D = scanner.nextInt();
        // 要求点数
        int G = scanner.nextInt();

        int[] P = new int[D];
        int[] C = new int[D];

        for (int i = 0; i < D; i++) {
            P[i] = scanner.nextInt();
            C[i] = scanner.nextInt();
        }

        int minNum = 0;
        // 2^n
        for (int bit = 0; bit < (1 << D); bit++) {
            int point = 0;
            int problemNum = 0;

            // その時たったbitに応じて全問正解する難易度を決定(決め打ち)する
            for (int i = 0; i < D; i++) {
                if (((bit >> i) & 1) == 1) {
                    // そのbitが立ってるとき全問正解したとする
                    point += P[i] * 100 * (i + 1) + C[i];
                    problemNum += P[i];
                }
            }

            // 全問正解のみで要求点数をクリアしていた場合
            if (point >= G) {
                if (minNum == 0 || minNum > problemNum) {
                    minNum = problemNum;
                    continue;
                }
            }

            // 配点の高い問題をいくつか解くことでクリアできるはずなので配点の高い問題から確認する
            for (int i = D - 1; i >= 0; i--) {
                // 全問正解ですでにカウントした問題
                if (((bit >> i) & 1) == 1) continue;

                for (int j = 0; j < P[i]; j++) {
                    if (point >= G) {
                        if (minNum == 0 || minNum > problemNum) {
                            minNum = problemNum;
                        }
                        break;
                    }
                    point += (i + 1) * 100;
                    problemNum++;
                }
            }
        }
        System.out.println(minNum);
    }
}
