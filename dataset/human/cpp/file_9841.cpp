#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 1e9+7;
long long suf[N][30], ans;
int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=n-1;i>=0;i--){
        suf[i][s[i] - 'a']++;
        for(int j=0;j<26;j++){
            suf[i][j] += suf[i+1][j];
        }
    }

    for(int i=0;i<n;i++){
        long long res = 1;
        int k = s[i] - 'a';
        for(int j=0;j<26;j++){
            if(j!=k){
                res *= (suf[i+1][j] + 1);
                res %= M;
            }
        }
        ans += res;
        ans %= M;
    }

    cout << (ans%M + M)%M << '\n';


    return 0;
}
