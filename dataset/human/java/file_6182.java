import java.util.Scanner;

/**
 * ABC051B_Sum_of_Three_Integers
 */
public class Main {
    private static Scanner sc;

    public static void main(String[] args) {
        sc = new Scanner(System.in);

        int K = sc.nextInt();
        int S = sc.nextInt();

        // 1つずつ組み合わせを探し、Sに一致する場合のみカウント
        int answer = 0;

        // 最終ループは答えが1つあるかないかで判定可能
        for (int i = 0; i <= K; i++) {
            for (int j = 0; j <= K; j++) {
                if (0 <= S - (i + j) && S - (i + j) <= K) {
                    // forループの0から、Kまでの2つの条件から設定。合致すれば1つカウント
                    answer++;
                }
            }
        }

        System.out.println(answer);

        sc.close();
    }
}
