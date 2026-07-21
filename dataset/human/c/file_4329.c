#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007

int main(){
    int n,m,i;
    int a[100000];
     long long int stair[100001];
   
    scanf("%d %d",&n,&m);
    
    for(i=0;i<=n;i++){
        stair[i] = -1;
    }

    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    stair[0] = 1;

    if(a[0]==1){
        stair[1] = 0;
    }
    else{
    stair[1] = 1;
    }

    for(i=0;i<m;i++){
        stair[a[i]]=0;
    }

    for(i=2;i<=n;i++){
        if(stair[i]==0){
        }
        else{
        stair[i] = (stair[i-2]+stair[i-1])%MOD;
        }
    }

    printf("%lld\n",stair[n]);
    return 0;
}
