#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int a_sum[n] = {};
    cin >> a_sum[0];
    for(int i = 1;i < n;i++)
    {
        long long int a;
        cin >> a;
        a_sum[i] = a_sum[i - 1] + a;
    }
    long long int mini = LLONG_MAX;
    for(int i = 0;i < n - 1;i++)
    {
        if(fabs(a_sum[n - 1] - 2 * a_sum[i]) < mini)
        {
            mini = fabs(a_sum[n - 1] - 2 * a_sum[i]);
        }
    }
    cout << mini;

    return 0;
}
