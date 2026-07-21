#include <bits/stdc++.h>

using namespace std;

int n;
int f[100010];
char ch[200010], conv[200010];
int ans = 0;
const int MOD = 1e9 + 7;

int mul(long long a, long long b){
    return (a * b) % MOD;
}

int main(){
    scanf("%d", &n);

    f[0] = 1;
    for(int i = 1; i <= n; i++) f[i] = mul(f[i - 1], i);

    scanf(" %s", ch);
    
    int val = 0;

    ans = 1;
    for(int i = 0; i < 2 * n; i++){
        if(val & 1){
            if(ch[i] == 'W') conv[i] = 'L';
            else conv[i] = 'R';
        } else {
            if(ch[i] == 'W') conv[i] = 'R';
            else conv[i] = 'L';
        }

        if(conv[i] == 'L') val++;
        else ans = mul(ans, val), val--;

        if(val < 0) break;
    }

    if(val != 0) ans = 0;

    printf("%d\n", mul(ans, f[n]));
    
    return 0;
}
