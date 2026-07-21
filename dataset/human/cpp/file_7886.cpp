#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int ll;

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    ll sum = 0;

    for (int i = 0; i < N;i++){
        cin >> a[i];
        sum += a[i];
    }

    ll res=10000000000LL,tmp=0;
    for (int i = 0; i < N;i++){
        tmp += a[i];
        if(i+1<N)
            res = min(res, abs(sum - 2 * tmp));
    }
    cout << res << endl;
}
