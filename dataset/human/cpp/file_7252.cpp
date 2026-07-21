#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e10;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    vector<long long> sum(N+1, 0);

    for(int i = 0; i < N; i++){
        sum[i+1] += sum[i] + a[i];
    }
  
    long long ans = INF;
    for(int i = 1; i < N; i++){
        long long now = llabs(sum[i] - (sum[sum.size()-1] - sum[i]));
        if(ans > now) ans = now;
    }
    cout << ans << endl;

}
