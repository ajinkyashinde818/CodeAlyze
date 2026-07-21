#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define lld long long int

int main(){
    int n;
    scanf("%d", &n);
    int a[n+1], f[n+1];
    rep(i, 1, n+1){
        scanf("%d", &a[i]);
        f[i] = 0;
    }
    int x=1;
    int ans = 0;
    while(1){
        if(x == 2){
            printf("%d", ans);
            break;
        }else if(f[a[x]]){
            printf("-1");
            break;
        }else{
            f[a[x]] = 1;
            x = a[x];
            ans++;
        }
    }

    return 0;
}
