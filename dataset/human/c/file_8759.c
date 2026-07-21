#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
typedef long long ll;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define swap(a,b) {ll tp=a;a=b;b=tp;}
const ll MOD = 1000000007;

int main(){
    int n; scanf("%d", &n);
    int a[101010], ch[101010] = {0};
    rep(i,n) scanf("%d", a+i+1);
    int ans = 0, tmp = 1;
    while(tmp != 2 && ch[tmp] == 0){
        ch[tmp] = 1;
        ans++;
        tmp = a[tmp];
    }
    if(tmp != 2) ans=-1;
    printf("%d", ans);
}
