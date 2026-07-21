#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int parr[220000],part[220000];

typedef struct{
    int r;
    int t;
    int i;
    int count;
} pair_t;

int sort1(const void *a, const void *b){
    if ( ((pair_t*)a)->r - ((pair_t*)b)->r >0 ) {
        return 1;
    }
    if ( ((pair_t*)a)->r - ((pair_t*)b)->r <0 ) {
        return -1;
    }
    if ( ((pair_t*)a)->r - ((pair_t*)b)->r ==0 ) {
        if ( ((pair_t*)a)->t - ((pair_t*)b)->t >0 ) {
            return 1;
        }
        if ( ((pair_t*)a)->t - ((pair_t*)b)->t <0 ) {
            return -1;
        }
    }
    return 0;
}

int sort2(const void *a, const void *b){
    if ( ((pair_t*)a)->i - ((pair_t*)b)->i >0 ) {
        return 1;
    }
    if ( ((pair_t*)a)->i - ((pair_t*)b)->i <0 ) {
        return -1;
    }
    return 0;
}

int findr(int x){
    if (parr[x]==x){
        return x;
    } else {
        return parr[x]=findr(parr[x]);
    }
}

void uniter(int x, int y){
    x=findr(x);
    y=findr(y);
    if(x==y){
        return ;
    }
    parr[y]=x;
}

int findt(int x){
    if (part[x]==x){
        return x;
    } else {
        return part[x]=findt(part[x]);
    }
}

void unitet(int x, int y){
    x=findt(x);
    y=findt(y);
    if(x==y){
        return ;
    }
    part[y]=x;
}

int main(void){
    int n,k,l,p,q,r,s;
    scanf("%d%d%d",&n,&k,&l);
    
    for (int i=0; i<n; i++){
        parr[i]=i;
        part[i]=i;
    }
    
    for (int i=0; i<k; i++){
        scanf("%d%d",&p,&q);
        p--;
        q--;
        uniter(p,q);
    }
    
    for (int i=0; i<l; i++){
        scanf("%d%d",&r,&s);
        r--;
        s--;
        unitet(r,s);
    }
    
    pair_t pair[n];
    for (int i=0; i<n; i++){
        pair[i].r=findr(i);
        pair[i].t=findt(i);
        pair[i].i=i;
        pair[i].count=1;
    }
    qsort (pair,n,sizeof(pair_t),sort1);
    for (int i=1; i<n; i++){
        if (pair[i].r==pair[i-1].r && pair[i].t==pair[i-1].t){
            pair[i].count+=pair[i-1].count;
        }
    }
    for (int i=n-1; i>=0; i--){
        if (pair[i].r==pair[i+1].r && pair[i].t==pair[i+1].t){
            pair[i].count=pair[i+1].count;
        }
    }
    qsort (pair,n,sizeof(pair_t),sort2);
    for (int i=0; i<n; i++){
        printf("%d ",pair[i].count);
    }
    printf("\n");
	return 0 ;
}
