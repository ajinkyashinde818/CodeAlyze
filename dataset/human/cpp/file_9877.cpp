#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main(){
    int n;cin >> n;
    string s;cin >> s;
    ll count[26];
    for(int i=0;i<26;i++){
        count[i] = 0;
    }
    for(int i=0;i<n;i++){
        count[s[i]-'a'] ++;
    }
    ll ans = 1;
    for(int i=0;i<26;i++){
        ans = (ans*(count[i]+1))%(1000000007);
    }
    if(ans == 0){
        ans = 1000000006;
    }
    else{
        ans -=1;
    }
    cout << ans << endl;
    return 0;
}
