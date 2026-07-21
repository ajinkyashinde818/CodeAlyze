#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ll mod = 1e9 + 7;
    int N;  cin >> N;
    string S;  cin >> S;
    if(S[0] == 'W' || S[2*N-1] == 'W'){
        cout << 0 << endl;
        return 0;
    }

    vector<int> s(2*N, 0);
    for(int i=1; i<2*N; i++){
        if(S[i] == S[i-1]) s[i] = 1 - s[i-1];
        if(S[i] != S[i-1]) s[i] = s[i-1];
    }
    if(s[2*N-1] == 0){
        cout << 0 << endl;
        return 0;
    }

    vector<int> cntL(2*N), cntR(2*N);
    for(int i=0; i<2*N; i++){
        if(i > 0){
            cntL[i] += cntL[i-1];
            cntR[i] += cntR[i-1];
        }
        if(s[i] == 0){
            cntL[i]++;
        }else{
            cntR[i]++;
        }
    }
    if(cntL[2*N-1] != cntR[2*N-1]){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int i=0; i<2*N; i++){
        if(s[i] == 1){
            ans = (ans * (cntL[i] - (cntR[i] - 1)))%mod;
        }
    }
    for(int i=1; i<=N; i++){
        ans = (ans * i)%mod;
    }
    cout << ans << endl;
}
