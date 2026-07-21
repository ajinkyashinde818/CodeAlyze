#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N; cin >> N;
    long long SUM=0;
    vector<long long> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i]; SUM+=a[i];
    }
    long long ans=INFLL;
    for(int i=0;i<N-1;i++){
        SUM-=2*a[i];
        ans = min(ans, abs(SUM));
    }
    cout << ans << endl;
}
