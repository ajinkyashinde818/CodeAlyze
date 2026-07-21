#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

#define rep(i,begin,end) for(int i=begin; i<end; i++)

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    char a[n][n], b[m][m];
    rep(i, 0, n){
        char s[n+1];
        scanf("%s", s);
        rep(j, 0, n){
            a[i][j] = s[j];
        }
    }
    rep(i, 0, m){
        char s[m+1];
        scanf("%s", s);
        rep(j, 0, m){
            b[i][j] = s[j];
        }
    }
    int q = n-m+1;
    int ans = 0;
    rep(i, 0, q){
        rep(j, 0, q){
            int f = 1;
            rep(k, i, i+m){
                rep(l, j, j+m){
                    if(a[k][l] != b[k-i][l-j]){
                        f = 0;
                    }
                }
            }
            if(f){
                ans = 1;
            }
        }
    }
    printf(ans?"Yes":"No");

    return 0;
}
