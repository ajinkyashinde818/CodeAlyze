//set many funcs template
//Ver.20190820
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<assert.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

int max(int a,int b){if(a>b){return a;}return b;}
int min(int a,int b){if(a<b){return a;}return b;}
int zt(int a,int b){return max(a,b)-min(a,b);}
int round(int a,int b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
int ceil(int a,int b){if(a%b==0){return a/b;}return (a/b)+1;}
int gcd(int a,int b){int c;while(b!=0){c=a%b;a=b;b=c;}return a;}
int lcm(int a,int b){int c=gcd(a,b);a/=c;return a*b;}
int nCr(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
int nHr(int a,int b){return nCr(a+b-1,b);}
int fact(int a){int i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
int pow(int a,int b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
int dsum(int x){int r=0;while(x){r+=(x%10);x/=10;}return r;}
int dsumb(int x,int b){int r=0;while(x){r+=(x%b);x/=b;}return r;}
int sankaku(int x){return ((1+x)*x)/2;}
void swap(int *a,int *b){int c;c=(*a);(*a)=(*b);(*b)=c;}
long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}
long long llzt(long long a,long long b){return llmax(a,b)-llmin(a,b);}
long long llround(long long a,long long b){if((a%b)*2 >= b){return (a/b)+1;}return a/b;}
long long llceil(long long a,long long b){if(a%b==0){return a/b;}return (a/b)+1;}
long long llgcd(long long a,long long b){long long c;while(b!=0){c=a%b;a=b;b=c;}return a;}
long long lllcm(long long a,long long b){long long c=llgcd(a,b);a/=c;return a*b;}
long long llnCr(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
long long llnHr(long long a,long long b){return llnCr(a+b-1,b);}
long long llfact(long long a){long long i,r=1;for(i=1;i<=a;i++){r*=i;}return r;}
long long llpow(long long a,long long b){long long i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}
long long lldsum(long long x){long long r=0;while(x){r+=(x%10);x/=10;}return r;}
long long lldsumb(long long x,long long b){long long r=0;while(x){r+=(x%b);x/=b;}return r;}
long long llsankaku(long long x){return ((1+x)*x)/2;}
void llswap(long long *a,long long *b){long long c;c=(*a);(*a)=(*b);(*b)=c;}
double dbmax(double a,double b){if(a>b){return a;}return b;}
double dbmin(double a,double b){if(a<b){return a;}return b;}
double dbzt(double a,double b){return dbmax(a,b)-dbmin(a,b);}
void dbswap(double *a,double *b){double c;c=(*a);(*a)=(*b);(*b)=c;}
void chswap(char *a,char *b){char c;c=(*a);(*a)=(*b);(*b)=c;}
int sortfncsj(const void *a,const void *b){if(*(int *)a>*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int sortfnckj(const void *a,const void *b){if(*(int *)a<*(int *)b){return 1;}if(*(int *)a==*(int *)b){return 0;}return -1;}
int llsortfncsj(const void *a,const void *b){if(*(long long *)a>*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int llsortfnckj(const void *a,const void *b){if(*(long long *)a<*(long long *)b){return 1;}if(*(long long *)a==*(long long *)b){return 0;}return -1;}
int dbsortfncsj(const void *a,const void *b){if(*(double *)a>*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int dbsortfnckj(const void *a,const void *b){if(*(double *)a<*(double *)b){return 1;}if(*(double *)a==*(double *)b){return 0;}return -1;}
int strsortfncsj(const void *a,const void *b){return strcmp((char *)a,(char *)b);}
int strsortfnckj(const void *a,const void *b){return strcmp((char *)b,(char *)a);}
int chsortfncsj(const void *a,const void *b){if(*(char *)a>*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}
int chsortfnckj(const void *a,const void *b){if(*(char *)a<*(char *)b){return 1;}if(*(char *)a==*(char *)b){return 0;}return -1;}

void shuffledget(int x[],int n){
    int i,b[524288],p,c;
    for(i=0;i<n;i++){
        b[i]=i;
    }
    for(i=n;i>=1;i--){
        p=rand()%i;
        c=b[i-1];b[i-1]=b[p];b[p]=c;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x[b[i]]);
    }
}

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};
int dx8[8]={-1,-1,-1,0,0,1,1,1};
int dy8[8]={-1,0,1,-1,1,-1,0,1};

int search(int x,int a[],int n){
    int st=0,fi=n-1,te;
    while(st<=fi){
        te=(st+fi)/2;
        if(a[te]<x){st=te+1;}else{fi=te-1;}
    }
    return st;
}

void prarr(int arr[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i){printf(" ");}
    printf("%d",arr[i]);
  }
  printf("\n");
  return;
}

void getperm(int a[],int n){
  int i,p;
  for(i=0;i<n;i++){
    a[i]=i;
  }
  for(i=n-1;i>=1;i--){
    p=rand()%(i+1);
    swap(&a[p],&a[i]);
  }
}

typedef struct{
int val;
int node;
}sd;

int sdsortfnc(const void *a,const void *b){
if(((sd*)a)->val < ((sd*)b)->val){return -1;}
if(((sd*)a)->val > ((sd*)b)->val){return 1;}
return 0;
}

void coordinate_comp(int a[],int n){
  int i,c=0;
  sd dat[524288];
  for(i=0;i<n;i++){
    dat[i].val=a[i];
    dat[i].node=i;
  }
  qsort(dat,n,sizeof(dat[0]),sdsortfnc);
  a[dat[0].node]=c;
  for(i=1;i<n;i++){
    if(dat[i-1].val!=dat[i].val){c++;}
    a[dat[i].node]=c;
  }
}

void prdp(int dp[205][205][205],int h,int w){
  int i,j,k;
  for(i=1;i<=h;i++){
    for(j=i;j<=h;j++){
      for(k=1;k<=w;k++){
        fprintf(stderr,"[%d,%d] %d : %d\n",i,j,k,dp[i][j][k]);
      }
    }
  }fprintf(stderr,"\n");
}

int main(void){
  char s[205][205];
  int a[205][205]={0};
  int i,j,k,l,h,w,res=0,bf,v;
  int st,fi,typ,ntyp;
  //dp[column[a,b]][leftmost row]={max rightmost row}
  int dp[205][205][205];
  int ndp[205][205][205];
  scanf("%d%d",&h,&w);
  for(i=1;i<=h;i++){
    scanf("%s",&s[i][1]);
  }
  for(j=1;j<=w;j++){
    for(i=1;i<=h;i++){
      if(s[i][j]=='#'){a[i][j]++;}
      a[i+1][j]+=a[i][j];
    }
  }
  
  for(i=1;i<=h;i++){
    for(j=i;j<=h;j++){
      bf=1;typ=-1;
      for(k=1;k<=w+1;k++){
        if((a[j][k]-a[i-1][k])==0){ntyp=0;}
        else if((a[j][k]-a[i-1][k])==(j-i+1)){ntyp=1;}
        else{ntyp=-1;}
        if(k==w+1 || ntyp==-1){
          //printf("err [%d,%d]:%d\n",i,j,k);
          for(l=bf;l<=k-1;l++){dp[i][j][l]=k-1;}
          dp[i][j][k]=-1;
          bf=k+1;
        }
        else if(typ!=ntyp){
          for(l=bf;l<=k-1;l++){dp[i][j][l]=k-1;}
          bf=k;
        }
        typ=ntyp;
        ndp[i][j][k]=-1;
      }
    }
  }
  
  //prdp(dp,h,w);

  while(dp[1][h][1]!=w){
    res++;
    
    for(i=1;i<=h;i++){
      for(j=i;j<=h;j++){
        for(k=1;k<=w;k++){
          v=dp[i][j][k];
          if(v<=0){continue;}
          if(v==w){continue;}
          ndp[i][j][k]=max(dp[i][j][v+1],ndp[i][j][k]);
        }
      }
    }

    for(k=1;k<=w;k++){
      for(i=1;i<h;i++){
        st=i;fi=i+1;
        while(1<=st && fi<=h){
          v=min(dp[st][i][k],dp[i+1][fi][k]);
          if(v<=0){break;}
          ndp[st][fi][k]=max(v,ndp[st][fi][k]);
          if(st==1){fi++;continue;}
          if(fi==h){st--;continue;}
          if(dp[st-1][i][k]>dp[i+1][fi+1][k]){st--;}
          else{fi++;}
        }
      }
    }
    
    for(i=1;i<=h;i++){
      for(j=h;j>=i;j--){
        for(k=1;k<=w;k++){
          dp[i][j][k]=max(ndp[i][j][k],dp[i][j][k]);
          ndp[i][j-1][k]=max(dp[i][j][k],ndp[i][j-1][k]);
          ndp[i+1][j][k]=max(dp[i][j][k],ndp[i+1][j][k]);
          ndp[i][j][k]=-1;
        }
      }
    }
    //prdp(dp,h,w);
  }
  printf("%d\n",res);
  return 0;
}
