//「全問解く」:1一問も解かない」:0 としてBIT全探索→scoreに値を代入
//例.d=4,i=1011なら「100点、200点、400点の問題を全部解く」
//もしscoreがgに満たなかったら、iのビットを桁が大きいほうからしらべて0ならばその得点の問題を1問ずつ解く
//一問解くたびにscore>=gを確認し、真なら最小値と比較、最小値を下回れば更新しループを抜ける
//もし各回においてscore<gなら、p-1回まで行う
//このようなビットは高々1つでよい（p問解くならそのビットが1になっているのと同じである）
import java.util.*;
import static java.lang.System.*;
import static java.lang.Math.*;
public class Main {
    public static void main(String[] $) {
        Scanner sc = new Scanner(in);
        int d=sc.nextInt();
        int g=sc.nextInt();
        int[] p=new int[d+1];
        int[] c=new int[d+1];
        for (int i = 0; i < d; i++) {
            p[i+1]=sc.nextInt();
            c[i+1]=sc.nextInt();
        }
        int ans=1000000000;
        for (int i = 0; i < (1 << d); i++) {
            //temp:iを決めた時の回答数
            //score:iを決めた時の得点
            int temp=0;
            long score=0;
            for (int j = 0; j < d; j++) {
                if((1&(i>>j))==1) {
                    score += (j + 1) * 100 * p[j + 1] + c[j + 1];
                    temp += p[j + 1];
                }
            }
            if(score>=g){
                ans=min(ans,temp);
            }else {
                //高得点の問題から貪欲をする
                for (int j = d-1; j > -1; j--) {
                    if((1&(i>>j))==1)continue;
                    else {
                        for (int k = 1; k < p[j + 1]; k++) {
                            score += (j + 1) * 100;
                            temp += 1;
                            if(score>=g) {
                                ans = min(ans, temp);
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }
        out.println(ans);
    }
}
