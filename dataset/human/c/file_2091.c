#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define LL long long
#define DB double
#define INF 1145141919810364364
#define PI 3.14159265358979
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)<(y)?(y):(x))
#define FOR(i,a,n) for(i=a;i<n;i++)
#define MOD 1000000007
//#define MOD 998244353
#define ERR 0.00000001
#define NUM 200010

void swap(LL* a,LL* b){LL tmp=*a;*a=*b;*b=tmp;}
void YN(int a){if(a==1)printf("Yes\n");if(a==0)printf("No\n");}
LL lpow(LL a,LL n){LL ans=pow(a,n)*10;if(ans%10<5)return ans/10;return ans/10+1;}
LL dup(LL a,LL d){if(a%d==0)return a/d;else return a/d+1;}
LL GCD(LL a,LL b){LL c=1,tmp=MAX(a,b);b=MIN(a,b);a=tmp;while(c!=0){c=a%b;a=b;b=c;}return a;}
LL LCM(LL a,LL b){return a*b/GCD(a,b);}
int lcmp(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return 1;if(*(LL*)a<*(LL*)b)return -1;return 0;}
int lcmpr(const void* a,const void* b){if(*(LL*)a>*(LL*)b)return -1;if(*(LL*)a<*(LL*)b)return 1;return 0;}
int ccmp(const void* a,const void* b){return *(char*)a-*(char*)b;}
int ccmpr(const void* a,const void* b){return *(char*)b-*(char*)a;}
int scmp(const void* a,const void* b){return strcmp(*(char**)a,*(char**)b);}
int scmpr(const void* a,const void* b){return strcmp(*(char**)b,*(char**)a);}
LL mod(LL a,LL m){if(a<0)return a%m+m;else return a%m;}
LL DIV(LL a,LL d){LL m=MOD,x=1,y=0,k;while(m){k=d/m;d-=k*m;swap(&m,&d);x-=k*y;swap(&x,&y);}return mod(a*mod(x,MOD),MOD);}
LL FAC(LL a){LL i,ans=1;FOR(i,1,a+1){ans*=i;if(MOD>0&&ans>MOD)ans%=MOD;}return ans;}
LL POW(LL a,LL n){LL ans=1;while(n>0){if(n&1)ans=ans*a%MOD;a=a*a%MOD;n>>=1;}return ans;}
LL fact[NUM],finv[NUM],inv[NUM];
void comi(){LL i;fact[0]=fact[1]=1;finv[0]=finv[1]=1;inv[1]=1;FOR(i,2,NUM){fact[i]=fact[i-1]*i%MOD;inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;finv[i]=finv[i-1]*inv[i]%MOD;}}
LL com(LL n,LL k){if(n<k||n<0||k<0)return 0;return fact[n]*(finv[k]*finv[n-k]%MOD)%MOD;}

int main(){
  LL i,ans=0;
  char N[10000005];
  scanf("%s",N);
  LL n=strlen(N);
  for(i=n-1;i>=0;i--){
    if(N[i]-'0'<5)ans+=N[i]-'0';
    if(N[i]-'0'>5){
      if(i==0)ans+=11-(N[i]-'0');
      else N[i-1]++,ans+=10-(N[i]-'0');
    }
    if(N[i]-'0'==5){
      if(i>0){
        if(N[i-1]-'0'>4)N[i-1]++;
        /*if(N[i-1]-'0'==4){
          if(i>1)if(N[i-1]-'0'==4&&N[i-2]-'0'>4)N[i-1]++;
        }*/
      }
      ans+=5;
    }
  }

  printf("%lld\n",ans);
	return 0;
}
