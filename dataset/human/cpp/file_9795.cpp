#include <bits/stdc++.h>
using namespace std;
long MOD = 1e9+7;
int main(){
    long n,a[26]={},cnt=1;
    string s;
    cin >> n >> s;
    for(int i=0;i<n;i++) a[s[i]-97]++;
    for(int i=0;i<26;i++) cnt =  (cnt * (a[i]+1))%MOD;
    cout << cnt-1 << endl;
}
