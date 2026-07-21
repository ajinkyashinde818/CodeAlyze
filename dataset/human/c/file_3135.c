#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD1 1000000007
#define MOD2 998244353
#define LIMIT1 200002
#define LIMIT2 500002
#define INF (1<<29)*2
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define ffor(i, a, b, c) for(i=a;i<=b;i+=c)
#define rep(i, n) for(i=0;i<n;i++)
#define max(a, b) ((a)>(b) ? (a) : (b))
#define min(a, b) ((a)<(b) ? (a) : (b))
#define bit(n) (1LL<<(n))
#define median(a, b) (a+b)/2.0
#define ABS(a) (a >= 0 ? (a) : (-a))
#define zt(a, b) (max(a,b)-min(a,b))
ll swap(ll *a,ll *b){ll tmp;tmp=*a;*a=*b;*b=tmp;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll sum(ll *a,ll n){ll total=0,i;if(n<=0){return 0;}else{rep(i,n) total+=a[i];return total;}}
ld avg(ll *a,ll n){if(n<=0){return 0;}else{return (ld)sum(a,n)/n;}}
ll nPr(int n,int r){ll i,result=1;rep(i,r){result*=(ll)(n-i);}return result;}
ll nCr(int n,int r){ll i,result=1;rep(i,r){result*=(ll)(n-i);result/=(ll)(i+1);}return result;}
#define fact(n) nPr((int)n,(int)n)
#define nHr(n,r) nCr((int)(n+r+1),(int)r)
#define sankaku(x) ((1+x)*x)/2
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int stack[LIMIT2];//stack[0]=count;
int queue[LIMIT2];//queue[0]=start,queue[1]=length;
int upll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0; }
int downll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0; }
int upint(const void *a, const void *b) { return *(int *)a < *(int *)b ? -1 : *(int *)a > *(int *)b ? 1 : 0; }
int downint(const void *a, const void *b) { return *(int *)a < *(int *)b ? 1 : *(int *)a > *(int *)b ? -1 : 0; }
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }
int upchar(const void* left, const void* right) {return strcmp((char *)left,(char *)right);}
//qsort(s,n,sizeof(s[0]),upchar);
int downchar(const void* left, const void* right) {return strcmp((char *)right,(char *)left);}
//qsort(s,n,sizeof(s[0]),downchar);
int push(int n){
    if(stack[0]>=LIMIT2) return -1;
    stack[0]++;
    stack[stack[0]] = n;
    return 1;
}
int pop(){
    if(stack[0]<=0) return -1;
    stack[0]--;
    return stack[stack[0]+1];
}
int enqueue(int n){
    if(queue[0]+queue[1]>=LIMIT2) return -1;
    queue[queue[0]+queue[1]] = n;
    queue[1]++;
    return 1;
}
int dequeue(){
    int result;
    if(queue[1]<=0) return -1;
    result = queue[queue[0]];
    queue[0]++;
    queue[1]--;
    if(queue[1]==0){
        queue[0] = 2;//queue reset
    }else if(queue[1]==1){
        queue[2] = queue[queue[0]];//only oneth
        queue[0] = 2;
    }
    return result;
}

void initialize(){
    stack[0] = 0;//stack size
    queue[0] = 2;//queue start
    queue[1] = 0;//queue length
}

int main(void){
    initialize();
    int n,m,i,j,k,x,y,value,b,c;
    int a[LIMIT2]={0},q[LIMIT1]={0},r[LIMIT2]={0};
    ll result=0;
    int s[LIMIT2];
  
  scanf("%d %d",&k,&n);
  rep(i,n) scanf("%d",&a[i]);
  x = zt(a[0],a[n-1]);
  if(x > k/2) x = k-x;
  for(i=1;i<n-1;i++){
    y = zt(a[i],a[i+1]);
    if(y > k/2) y = k-y;

    x = max(x, y);
  }
  printf("%d", k-x);
     
    return 0;
}
