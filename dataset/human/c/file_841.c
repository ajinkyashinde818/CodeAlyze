#include<stdio.h>
int main(){
    long N,K;
    scanf("%ld %ld", &N,&K);
    long d[40],j=1,r=1;
    d[0]=K;
    for (long i=K;i>0;i/=2){
        if(K&j){
            d[r++]=(K-j)|(j-1);
        }
        j*=2;
    }
    long A,B,sum[40]={};
    for (long i=0;i<N;i++){
        scanf("%ld %ld", &A,&B);
        for (int j=0;j<r;j++){
            if((d[j]|A)==d[j]){
                sum[j]+=B;
            }
        }
    }
    for(long i=0;i<r;i++){
        if (sum[0]<sum[i]){
            sum[0]=sum[i];
        }
    }
    printf("%ld\n",sum[0]);
    return 0;
}
