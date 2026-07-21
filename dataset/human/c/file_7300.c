#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define LL long long
#define INF 1<<31-1
#define LNF 9223372036854775807
#define PI 3.14159265358979
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define FOR(i,a,n) for(i=a;i<n;i++)
#define MOD 1000000007
#define NUM 100005

void swap(int* a,int* b){int tmp=*a;*a=*b;*b=tmp;}
int abs(int a){if(a<0)return -a;return a;}
int dup(int a,int d){if(a%d==0)return a/d;else return a/d+1;}
int mod(int a,int m){if(a<0)return a%m+m;else return a%m;}
int GCD(int a,int b){int c=1,tmp=MAX(a,b);b=MIN(a,b);a=tmp;while(c!=0){c=a%b;a=b;b=c;}return a;}
int LCM(int a,int b){return a*b/GCD(a,b);}
int POW(int a,int n){LL ans=1;while(n>0){if(n&1)ans=ans*a%MOD;a=a*a%MOD;n>>=1;}return (int)ans;}
int icmp(const void* a,const void* b){return *(int*)a-*(int*)b;}
int lcmp(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return 1;if(*(LL*)a<*(LL*)b)return -1;return 0;}
int ccmp(const void* a,const void* b){return *(char*)a-*(char*)b;}
int scmp(const void* a,const void* b){return strcmp(*(char**)a,*(char**)b);}
LL fac[NUM],finv[NUM],inv[NUM];
void comi(){int i;fac[0]=fac[1]=1;finv[0]=finv[1]=1;inv[1]=1;FOR(i,2,NUM){fac[i]=fac[i-1]*i%MOD;inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
int com(int n,int k){if(n<k||n<0||k<0)return 0;return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;}


int main(){
  int H,W,K,i,j,k,l,n=0,m=1,ans=0;
  scanf("%d%d%d",&H,&W,&K);
  char s[H][W+1];
  int a[H][W],f[305];
  f[0]=-1;
  FOR(i,0,H)scanf("%s",s[i]);
  FOR(i,0,H)FOR(j,0,W)if(s[i][j]=='#'){
    f[++n]=i;
    break;
  }
  FOR(i,0,n)FOR(j,0,W){
    FOR(k,f[i]+1,f[i+1]+1)a[k][j]=m;
    if(s[f[i+1]][j]=='#')m++;
    else if(j==W-1)for(l=W-1;l>=0;l--){
      FOR(k,f[i]+1,f[i+1]+1)a[k][l]--;
      if(a[f[i+1]][l]==a[f[i+1]][l-1])break;
    }
  }
  FOR(i,f[n]+1,H)FOR(j,0,W)a[i][j]=a[i-1][j];

  FOR(i,0,H){
    FOR(j,0,W)printf("%d ",a[i][j]);
    printf("\n");
  }
	return 0;
}
