#include <stdio.h>
#define M 200005

int sort1(int,int);
int sort2(int,int);

int main(void){
    int n,i,R[M];
    int j,v;
    int maxv,minv;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&R[i]);
    }
    maxv=R[1]-R[0];
    minv=R[0];
    for(j=1;j<n;j++){
        maxv=sort1(maxv,R[j]-minv);
        minv=sort2(minv,R[j]);
    }
    printf("%d\n",maxv);
    return 0;
}

int sort1(int j,int v){
    if(j <= v)return v;
    else return j;
}

int sort2(int j,int v){
    if(j>=v)return v;
    else return j;
}
