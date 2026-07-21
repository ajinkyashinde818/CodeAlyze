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

ll n, k;
int a[222222], b[222222];

main(){
    scanf("%lld%lld", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]); 
        a[i]--;
    }
    int ans = 0;
    while(k){
        if(k & 1){
            ans = a[ans];
        }
        for(int i=0; i<n; i++)b[i] = a[a[i]];
        for(int i=0; i<n; i++)a[i] = b[i];
        k >>= 1;
    }
    printf("%d\n", ++ans);
    return 0;
}
