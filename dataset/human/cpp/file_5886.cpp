#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
ll C;
ll MAX[100010];
ll V[100010],X[100010];
ll ans = 0;

void unit()
{
    ll sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += V[i];
        if(i)MAX[i] = max(MAX[i - 1],sum - X[i]);
        else MAX[i] = sum - X[i];
        ans = max(ans,MAX[i]);
    }
    sum = 0;
    reverse(V,V + N);
    reverse(X,X + N);
    for(int i = 0; i < N; i++)
    {
        sum += V[i];
        ans = max(ans,sum - 2LL * (C - X[i]) + MAX[N - 2 - i]);
    }
    reverse(V,V + N);
    reverse(X,X + N);
}

int main()
{
    scanf("%d%lld",&N,&C);
    for(int i = 0; i < N; i++)
    {
        ll x,v;
        scanf("%lld%lld",&x,&v);
        X[i] = x;
        V[i] = v;
    }

    unit();
    reverse(X,X + N);
    reverse(V,V + N);
    for(int i = 0; i < N; i++)X[i] = C - X[i];
    unit();

    printf("%lld\n",ans);
    return 0;
}
