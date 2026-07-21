#include <bits/stdc++.h>
using namespace std;

int N;
long long C;
vector<long long> x, xinv;
vector<long long> v;

int main()
{
    cin >> N >> C;
    x.resize(N);
    xinv.resize(N);
    v.resize(N);
    for (int i=0; i<N; i++)
    {
        cin >> x[i] >> v[i];
        xinv[i] = C - x[i];
    }

    // 時計回りに(i+1)貫目まで食っていいときに片道/往復で得られる利得の最大値
    vector<long long> onewayR(N), roundR(N);
    long long kcalSum = 0;
    for (int i=0; i<N; i++)
    {
        kcalSum += v[i];
        if (i == 0)
        {
            onewayR[i] = fmax(kcalSum - x[i], 0);
            roundR[i] = fmax(kcalSum - 2 * x[i], 0);
        }
        else
        {
            onewayR[i] = fmax(kcalSum - x[i], onewayR[i-1]);
            roundR[i] = fmax(kcalSum - 2 * x[i], roundR[i-1]);
        }
    }

    vector<long long> onewayL(N), roundL(N);
    kcalSum = 0;
    for (int i=0; i<N; i++)
    {
        kcalSum += v[N-i-1];
        if (i == 0)
        {
            onewayL[N-i-1] = fmax(kcalSum - xinv[N-i-1], 0);
            roundL[N-i-1] = fmax(kcalSum - 2 * xinv[N - i - 1], 0);
        }
        else
        {
            onewayL[N-i-1] = fmax(kcalSum - xinv[N-i-1], onewayL[N-i]);
            roundL[N-i-1] = fmax(kcalSum - 2 * xinv[N-i-1], roundL[N-i]);
        }
    }

    long long result = fmax(onewayR[N-1], onewayL[0]);
    for (int i=1; i<N-1; i++)
    {
        long long tmp = fmax(onewayR[i] + roundL[i+1], onewayL[i] + roundR[i-1]);
        result = fmax(result, tmp);
    }

    cout << result << "\n";
    return 0;
}
