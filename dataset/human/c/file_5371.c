#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<tgmath.h>
#include<sys/queue.h>
#include<time.h>
#define ll long long
#define min(a, b) ((a) > (b) ? (b) : (a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define miin(a, b, c) min((a), min((b), (c)))
#define maax(a, b, c) max((a), max((b), (c)))
#define mod 1000000007
#define INF 1001001001

int n, m, x, c[15], a[15][15], ans = INF;
main(){
    scanf("%d%d%d", &n, &m, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &c[i]);
        for(int j=0; j<m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0; i < (1<<n); i++){
        int cost = 0, b[15] = {};
        bool flag = true;
        for(int j=0; j<n; j++){
            if((i>>j) & 1){
                cost += c[j];
                for(int k=0; k<m; k++){
                    b[k] += a[j][k];
                }
            }
        }
        for(int j=0; j<m; j++){
            if(b[j] < x){
                flag = false;
                break;
            }
        }
        if(flag)ans = min(ans, cost);
    }
    if(ans == INF){
        puts("-1");
        return 0;
    }
    printf("%d\n", ans);
    return 0;
}
