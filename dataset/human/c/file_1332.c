#include<stdio.h>
    #include<stdlib.h>
    int main(void){
    int N,M,i;
    int *a,*b;
    int no = 0;
    scanf("%d %d",&N,&M);
    a = (int *)malloc(N*sizeof(int)) ;
    b = (int *)malloc(N*sizeof(int)) ;
    int tmpa,tmpb;
    for(i=0;i<M;i++){
    scanf("%d %d",&tmpa,&tmpb);
    if(tmpa==1)a[tmpb]=1;
    if(tmpb==N)b[tmpa]=1;
    }
    for(i=0;i<N;i++){
    if(a[i]==1 && b[i]==1){
    no = 1;
    }
    }
    if(no == 1) printf("POSSIBLE");
    if(no == 0) printf("IMPOSSIBLE");
    return 0;
    }
