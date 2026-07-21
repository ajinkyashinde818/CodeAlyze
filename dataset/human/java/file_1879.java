import java.util.*;

import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int D = sc.nextInt();
        int G = sc.nextInt();

        int[] p = new int[D];
        int[] c = new int[D];
        for (int i = 0; i < D; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }

        // 完全に解く or 中途半端に解くしかない。その組み合わせの中で最も解く問題数が少ないものを探す
        // 完全に解くものの組み合わせをリストアップ
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < 1<<D; i++){
            int ans_tmp = 0;
            int score = 0;

            // 完全に解くものの合計
            for(int j = 0; j < D; j++){
                if((i>>j & 1) == 1){
                    score += 100 * (j + 1) * p[j] + c[j];
                    ans_tmp += p[j];
                }
                // スコア超えたらそこで終わり
                if(score >= G){
                    ans = Math.min(ans, ans_tmp);
                    continue;
                }
            }

            // 中途半端に解くものを探す
            for(int j = 0; j < D; j++){
                // 完全に解かれているものはスキップ
                if((i>>j & 1) == 1){ continue; }

                int score_tmp = score;
                int ans_tmp_tmp = ans_tmp;

                for(int k = 0; k < p[j] - 1; k++){
                    score_tmp += 100 * (j + 1);
                    ans_tmp_tmp++;

                    // スコア超えたらそこで終わり
                    if(score_tmp >= G){
                        ans = Math.min(ans, ans_tmp_tmp);
                        break;
                    }
                }
            }
        }
        out.println(ans);
    }
}
