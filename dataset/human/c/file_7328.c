#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define INF 1e18

//配列sの中で、keyより初めて大きくなる添字を出力
int binary_search_right(long* array,int min, int max, long key){
    if(min<max){
        int mid=min+(max-min)/2;

        if(key<array[mid]) return binary_search_right(array,min,mid,key);
        else if(key>array[mid]) return binary_search_right(array,mid+1,max,key);
    }
    if(key>array[min]) return min+1;
    return min;
}

int main(void){
    int A,B,Q;
    scanf("%d%d%d",&A,&B,&Q);

    //s[1]~s[A]に格納する
    long* s;
    NEW(s,A+2);
    for(int i=1;i<=A;i++){
        scanf("%ld",&s[i]);
    }
    s[0]=-INF;
    s[A+1]=INF;
    //t[1]~t[B]に格納する
    long* t;
    NEW(t,B+2);
    for(int i=1;i<=B;i++){
        scanf("%ld",&t[i]);
    }
    t[0]=-INF;
    t[B+1]=INF;

    //x[0]~x[Q-1]に格納する
    long* x;
    NEW(x,Q);
    for(int i=0;i<Q;i++){
        scanf("%ld",&x[i]);
    }

    for(int i=0;i<Q;i++){
        long b=binary_search_right(s,0,A+1,x[i]);
        long d=binary_search_right(t,0,B+1,x[i]);

        long ans=INF;
        long tmp;
        for(int j=b-1;j<=b;j++){
            for(int k=d-1;k<=d;k++){
                //printf("x = %ld s = %ld t = %ld ",x[i], s[j],t[k]);
                tmp=labs(s[j]-x[i])+labs(t[k]-s[j]);
                ans=MIN(ans,tmp);

                tmp=labs(t[k]-x[i])+labs(s[j]-t[k]);
                ans=MIN(ans,tmp);
                //printf("→ %ld\n",ans);
            }
        }
        printf("%ld\n",ans);
    }

    return 0;
}
