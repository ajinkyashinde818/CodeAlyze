#include <stdio.h>
#include <stdlib.h>

#define INFINITY 2147483647

void update(int,int);
int findMin(int,int);
int query(int,int,int,int,int);
int min(int,int);
void initRMQ(int);

int n; // the size of target array
int D[20000000];

int main()
{
    int rn,l,i;
    int a;
    int m;

    scanf("%d %d", &rn, &l);
    
    initRMQ(rn);
    
    for(i=0;i<rn;i++){
        scanf("%d", &a);
        update(i,a);
    }

    for(i=0;i<=rn-l;i++){
        m=findMin(i,i+l-1);
        if(i!=0) printf(" ");
        printf("%d",m);
    }

    printf("\n");

    return 0;
}

// input the required array size
void initRMQ(int rn){
    int i;

    n=1;

    // the size of array is power of 2
    while(n<=rn){
        n *= 2;
    }

    // initialize all node in segment tree
    for(i=0;i<(2*n-1-1);i++){
        D[i] = INFINITY;
    }
}

void update(int k, int a){
    k+=n-1;
    D[k]=a;
    while(k>0){
        k=(k-1)/2;
        D[k] = min(D[k*2+1],D[k*2+2]);
    }
}

// [a,b]
int findMin(int a,int b){
    return query(a,b+1,0,0,n);
}

// [a,b)
int query(int a,int b,int k,int l,int r){
    int vl,vr;
    //case1
    if(r<=a || b<=l) return INFINITY;

    //case2
    if(a<=l&&r<=b) return D[k];

    //case3
    vl = query(a,b,k*2+1,l,(l+r)/2);
    vr = query(a,b,k*2+2,(l+r)/2,r);
    return min(vl,vr);
}

int min(int x,int y){
    if(x<=y) return x;
    else return y;
}
