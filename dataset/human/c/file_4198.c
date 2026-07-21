#include <stdio.h>

int main(){
    int N,M,a;
    long long int MOD=1000000007;
    int stairs[100000]={};
    int broken[100000];
    scanf("%d %d",&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d",&broken[i]);
    }
    int j=0;
    for(int i=0;i<N;i++){
        if(i==broken[j]-1){
            j=j+1;
            continue;
        }else if(i==0){
            stairs[i]=1;
        }else if(i==1){
            stairs[i]=stairs[i-1]+1;
        }else{
            stairs[i]+=stairs[i-1];
            stairs[i]=stairs[i]%MOD;
            stairs[i]+=stairs[i-2];
            stairs[i]=stairs[i]%MOD;
        }
    }
    printf("%d",stairs[N-1]);
    return 0;
}
