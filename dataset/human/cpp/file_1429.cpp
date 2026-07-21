#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nsqrt(ll N)
{
        if(N == 0) return 0;
    ll x = N;
    ll y = floor((floor(N/x) + x)/2);
    while(y < x) {
        x = y;
        y = floor((floor(N/x) + x)/2);
    }
    return x;
}

void init_Qn(vector<ll> &Qn)
{
        int n = Qn.size();
        for(int i = 0; i < n; ++i) {
                Qn[i*i % n] = 1;
        }
}

bool square_detection(ll N)
{
        vector<ll> Q64(64, 0);
        vector<ll> Q63(63, 0);
        vector<ll> Q65(65, 0);
        vector<ll> Q11(11, 0);
        init_Qn(Q64);
        init_Qn(Q63);
        init_Qn(Q65);
        init_Qn(Q11);
        if(Q64[N%64] == 0) return false;
        ll r = N % 63*65*11;
        //if(Q63[N%63] == 0 || Q65[N%65] == 0 || Q11[N%11] == 0) return false;
        if(Q63[r%63] == 0) return false;
        //N %= 65*11;
        if(Q65[r%65] == 0) return false;
        r %= 11;
        if(Q11[r] == 0) return false;
        return nsqrt(N)*nsqrt(N) == N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(square_detection(8*n+1)) {
        int K = (1+nsqrt(8*n+1))/2;
        cout << "Yes" << endl;
        cout << K << endl;
        vector<vector<int>> ans(K, vector<int>(K-1, 0));
        int pos = K;
        for(int i = 0; i <K-1; ++i) {
            ans[0][i] = i+1;
        }
        for(int i = 1; i < K; ++i) {
            for(int j = 0; j < i; ++j) {
                ans[i][j] = ans[j][i-1];
            }
            for(int j = i; j < K-1; ++j) {
                ans[i][j] = pos + j-i;
            }
            pos += K-1-i;
        }
        for(int i = 0; i < K; ++i) {
            cout << K-1 << " ";
            for(int j = 0; j < K-1; ++j) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }else {
        cout << "No" << endl;
    }
}
