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
const int INF = 1000000000;
const int NIL = -1;

int n, k, s;

main(){
    scanf("%d%d%d", &n, &k, &s);
    for(int i=0; i<k; i++){
        printf("%d ", s);
    }
    for(int i=k; i<n; i++){
        printf("%d ", s==INF?1:INF);
    }
    return 0;
}
