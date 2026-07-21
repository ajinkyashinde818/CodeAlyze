#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
ll x[900000], v[900000];
ll m1[900000], m2[900000];
pii v1[900000], v2[900000], back1[900000], back2[900000];
int main(){
    ll n, c; scanf("%lld%lld", &n, &c);
    for(int i = 1; i <= n; i++)
        scanf("%lld%lld", &x[i], &v[i]);
    for(int i = 1; i <= n; i++){
        v1[i].first = v1[i-1].first - x[i]+x[i-1] + v[i];
        v1[i].second = v1[i].first - x[i];
        //cout << v1[i].first <<" "<< v1[i].second << endl;
    }
    x[n+1]=c;
    //puts("aaaaaaaa");
    for(int i = n; i>=1; i--){
        v2[i].first = v[i] + v2[i+1].first - x[i+1]+x[i];
        v2[i].second = v2[i].first - c + x[i];
        //cout << v2[i].first <<" "<< v2[i].second << endl;
    }

    //puts("bbbbbbbb");

    for(int j = n+1; j >= 0; j--){
        m1[j] = max(m1[j+1], v2[j].first);
        m2[j] = max(m2[j+1], v2[j].second);
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        //for(int j = i+1; j <= n+1; j++){
            /*printf("%d %d\n", v1[i].first, v2[j].first);
            printf("%lld %lld\n",v1[i].second+v2[j].first, v1[i].first+v2[j].second);
            */
        ans = max(ans, max(v1[i].second+m1[i+1], v1[i].first+m2[i+1]));
        //}
    }
    printf("%lld\n", ans);
}
