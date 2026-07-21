#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    string s;
    cin >> n >> s;
    int a[26] = {};
    for(int i = 0;i < n;i++)a[s[i]-'a']++;
    long long ans = 1;
    for(int i = 0;i < 26;i++){
        if(a[i] == 0)continue;
        ans = ans * (a[i]+1) % 1000000007;
    }
    cout << ans - 1;
}
