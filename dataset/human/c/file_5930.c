#include <stdio.h>

#define R_MAX 1000000000

int main(void) {
    int n; // 入力の数
    int maxv = -R_MAX; // ある時点までのR[j] - R[i]の最大値
                       // R[t]が1以上なので初期値は1 - R_MAX以下にする
    int minv; // ある時点までの価格の最小値
    int t; // 時刻を表すループ変数
    int Rt; // ループ内でscanfする用
    scanf("%d", &n);
    scanf("%d", &minv); // minvの初期値はR[0]としておく
    // 時刻t-1までのmaxvとminvが分かっているとき、
    // 時刻tまでのmaxvは、Rt - minvと時刻t-1までのmaxvを
    // 比較して大きい方。
    for (t = 1; t < n; t++) {
        scanf("%d", &Rt);
        if (Rt - minv > maxv) maxv = Rt - minv;
        if (Rt < minv) minv = Rt;
    }
    printf("%d\n", maxv);
    return 0;
}
