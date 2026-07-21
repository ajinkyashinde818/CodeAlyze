#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)
#define revrep(i,begin,end) for(int i=begin; i>end; i--)
#define lld long long int

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int t[2][n+1];
    rep(i, 0, n+1){
        t[0][i] = 0;
        t[1][i] = 0;
    }
    rep(i, 0, m){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == 1){
            t[0][b] = 1;
        }
        if(a == n){
            t[1][b] = 1;
        }
        if(b == 1){
            t[0][a] = 1;
        }
        if(b == n){
            t[1][a] = 1;
        }
    }
    int f = 0;
    rep(i, 1, n+1){
        if(t[0][i]==1 && t[1][i]==1){
            f = 1;
            break;
        }
    }
    printf(f ? "POSSIBLE" : "IMPOSSIBLE");

    return 0;
}
