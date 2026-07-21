#include<iostream>
#include<cmath>
using namespace std;
int main()
{

    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++) cin >> a[i];

    long long sum[N]; // 上からi枚目までの和(0-indexed)
    sum[0] = a[0];

    // 累積和を計算しておく
    for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + a[i];

    long long minimum = 1000000000000000000ll;
    for (int i = 0; i < N - 1; i++) {
        long long sum_snuke = 0, sum_kuma = 0;
        // すぬけくんは上からi枚目まで取る(0-indexed)
        sum_snuke = sum[i];
        // 残りをアライグマが取る
        sum_kuma = sum[N - 1] - sum_snuke;
        long long score = abs(sum_snuke - sum_kuma);
        // 2人の手札の差の絶対値が小さければ更新
        if (minimum > score) minimum = score;
    }
    // 最小値を出力
    cout << minimum << endl;

    return 0;
}
