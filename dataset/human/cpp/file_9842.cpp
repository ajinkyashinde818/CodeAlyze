#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int Mo=1000000007;
int w[26];
char s[100010];
int main() {
    int n,ans=1;
    scanf("%d%s",&n,s);
    for(int i=0;i<n;i++) ++w[s[i]-'a'];
    for(int i=0;i<26;i++) ans=1LL*ans*(w[i]+1)%Mo;
    cout<<(ans-1+Mo)%Mo;
    return 0;
}
