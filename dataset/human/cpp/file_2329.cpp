#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

int N;
ll A[100010];


int main()
{
    cin >> N;
    int mnsnum = 0;
    ll absmin = 1e10;
    ll res = 0;
    for(int i = 0; i < N; i++)
    {
        ll tmp;
        cin >> tmp;
        if(tmp < 0) mnsnum++;
        absmin = min(absmin, (tmp < 0? -1 * tmp: tmp));
        res += tmp < 0 ? -1*tmp : tmp;
    }
    if(mnsnum % 2 == 1)
    {
        res -= 2 * absmin;
    }

    cout << res << endl;
}
