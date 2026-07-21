#include <bits/stdc++.h>
using namespace std;

int main()
{
    //箱の中に入っているボールの数と目的のボールの数
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    //答え
    int ans = 0;

    //箱の数r(赤のボールが入った箱), g(緑のボールが入った箱)
    for (int r = 0; r <= N; r++)
    {
        for (int g = 0; g <= N; g++)
        {
            //赤と緑のボールの数の合計
            int sum = R * r + G * g;
            /*Nからsumを引いてそれが青のボールの数Bの倍数であれば
            ちょうどN個のボールが手に入る*/
            //sumがNより大きくなることはない
            if (sum <= N && (N - sum) % B == 0)
            {
                //cout << R * r << ' ' << G * g << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
