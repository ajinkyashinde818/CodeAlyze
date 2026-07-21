#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    int flag = 0;
    ll k = 10e8+7;
    int l[26];
    for(int i = 0; i < 26; i++){
        l[i] = 0;
    }
    for(int i = 0; i < n; i++){
        l[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(l[i] != 0){
            if(ans == 0){
                ans = l[i] + 1;
            }else{
                ans *= (l[i] + 1);
            }
            ans %= k;
        }
    }

    ans--;

    cout << ans << endl;
}
