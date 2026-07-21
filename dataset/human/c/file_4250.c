#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define LL long long
#define INF 1<<31-1
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define FOR(i,a,n) for(i=a;i<n;i++)
#define MOD 1000000007
#define NUM 100001
void swap(int* a,int* b){int tmp=*a;*a=*b;*b=tmp;}
int cmp(const void* a,const void* b){return *(int*)a-*(int*)b;}

int main() {
  int N,M,i,k=0;
  scanf("%d%d",&N,&M);
  int a[M],ans[N+2];
  FOR(i,0,M)scanf("%d",&a[i]);
  ans[0]=0;ans[1]=1;
  FOR(i,2,N+2){
    ans[i]=ans[i-2]+ans[i-1];
    if(a[k]==i-1){ans[i]=0;k++;}
    if(ans[i]>MOD)ans[i]%=MOD;
  }
  
  printf("%d\n",ans[N+1]);
	return 0;
}
