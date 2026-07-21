#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

typedef long long ll;

int asc(const void *arg1,const void *arg2) {return *((int *)arg2)-*((int *)arg1);}

bool used[100000],flag;
ll n,a[100000],count=0;

void dfs(int x){
  	count++;
    if(used[x-1]){ flag=false; return;}
    if(a[x-1]==2){ flag=true; return;} 
  	used[x-1]=true;
  	dfs(a[x-1]);
}

int main(){
    scanf("%lld",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    dfs(1);
    if(flag)printf("%lld",count);
    else printf("-1");
    
    return 0;
}
