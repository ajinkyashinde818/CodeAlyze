#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b, n, ans = 0;
    scanf("%d%d%d%d", &r, &g, &b, &n);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int rem = n-i*r-j*g;
            if(rem < 0 || rem%b != 0) continue;
            ans++;
        }
    }   
    printf("%d\n", ans);
}
