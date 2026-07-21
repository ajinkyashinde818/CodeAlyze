#include <bits/stdc++.h>

using namespace std;

const int NS = (int)1e5 + 4;
const long long MOD = (long long)1e9 + 7;
int N;
char s[NS * 2];

int main(){
    scanf("%d", &N);
    scanf("%s", s + 1);
    int val = 0;
    long long ans = 1;
    for(int i = 1; i <= N * 2; ++i){
        if((s[i] == 'B' && val % 2 == 0) || (s[i] == 'W' && val % 2 == 1)) ++val;
        else{
            ans = (ans * val) % MOD;
            --val;
        }
    }
    if(val){
        puts("0"); return 0;
    }
    for(int i = N; i >= 1; --i){
        ans = (ans * i) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
