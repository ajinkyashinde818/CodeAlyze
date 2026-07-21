#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define INFTY 999999

int gd(int n,int m){
    int a;
    int b;

    if(n<m){
        a=m;
        b=n;
    }
    else{
        a=n;
        b=m;
    }

    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}

int main(void){
    int A,B,K;
    scanf("%d %d %d",&A,&B,&K);

    int* G;
    NEW(G,101);

    int d=gd(A,B);
    int i=d;
    int count=0;
    while(i>0){
        if(d%i==0){
            count++;
            G[count]=i;
        }
        i--;
    }



    printf("%d\n",G[K]);

    return 0;
}
