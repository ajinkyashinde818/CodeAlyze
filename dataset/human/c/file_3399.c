#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define chmax(a,b) ((a)=(a)>(b)?(a):(b))
#define chmin(a,b) ((a)=(a)<(b)?(a):(b))
#define abs(p) ((p)>=(0)?(p):(-(p)))
#define MOD 1000000007
ll power(ll a,ll b){ll r=1;rep(i,b){r*=a;}return r;}
#define swap(a,b) do{ll w=(a);(a)=(b);(b)=w;}while(0)
#define swapd(a,b) do{double w=(a);(a)=(b);(b)=w}while(0)

//your code here!

int main(void){
    char s[100100];
    scanf("%s", s);
    ll N=strlen(s);
    while(N) {
        if     (N>=7 && strncmp(s+N-7, "dreamer", 7)==0) N -= 7;
        else if(N>=6 && strncmp(s+N-6, "eraser" , 6)==0) N -= 6;
        else if(N>=5 && (strncmp(s+N-5, "dream" , 5)==0 || strncmp(s+N-5, "erase", 5)==0)) N -= 5;
        else {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
