#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define REP(i,n) for(i=0;i<n;i++)
#define ll long long
#define PI M_PI

int main(void){
    int i, ctr= 0;
    int N, K; scanf("%d""%d",&N,&K);
    int h[N];
    REP(i,N) scanf("%d",&h[i]);
    
    REP(i,N){
        if(h[i] >= K) ctr++;
    }
    printf("%d",ctr);
    return 0;
}
