#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define MOD 1000000007
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define rep(i,n) for(i=0;i<n;i++)
int cmp(const void *a,const void*b){return *(int*)a-*(int*)b;}
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    int ans;
    if(n>=10){
        ans=r;
    }
    else{
        ans=r+100*(10-n);
    }
    printf("%d\n",ans);
    return 0;
}
