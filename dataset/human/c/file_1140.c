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
ll powll(ll a,ll b){ll r=1;rep(i,b){r*=a;}return r;}
#define swap(a,b) do{ll w=(a);(a)=(b);(b)=w;}while(0)
#define swapd(a,b) do{double w=(a);(a)=(b);(b)=w}while(0)
#define in(a) scanf("%lld", &(a))
#define in2(a,b) scanf("%lld %lld",&(a),&(b))
#define in3(a,b,c) scanf("%lld %lld %lld",&(a),&(b),&(c))
#define ind(a) scanf("%lf", &(a))
#define ins(a) scanf("%s", (a))
#define put(a) printf("%lld\n", (a))
#define putd(a) printf("%.15f\n", (a))
//      puts(a) printf("%s\n", a) 文字はこっち
//your code here!
/*int cmp(const void *a, const void *b){
    ll A=*(ll *)a, B=*(ll *)b;
    if(A==B)return 0;
    else return A>B ? 1:-1;//昇順ソート 1,2,....9
}
int cmp2(const void *a, const void *b){
    ll A=*(ll *)a, B=*(ll *)b;
    if(A==B)return 0;
    else return A>B ? -1:1;//降順
}*/

int cmp(const void *a, const void *b){
    char A=*(char *)a, B=*(char *)b;
    return A-B;//昇順ソート a,b....z
}
int cmp2(const void *a, const void *b){
    char A=*(char *)a, B=*(char *)b;
    return B-A;
}

int main(void){
    ll snum[101], tnum[101];
    char s[101], t[101];
    ins(s); ins(t);
    /*ll N=strlen(s);
    rep(i, N) snum[i] = s[i] - 'a';
    qsort(snum, N, sizeof(ll), cmp);
    rep(i, N) s[i] = 'a' + snum[i];
    N=strlen(t);
    rep(i, N) tnum[i] = t[i] - 'a';
    qsort(tnum, N, sizeof(ll), cmp2);
    rep(i, N) t[i] = 'a' + tnum[i];
    if(strcmp(s,t) < 0) puts("Yes");
    else puts("No");
    */

    //qsort万能説
    qsort(s, strlen(s), sizeof(char), cmp);
    qsort(t, strlen(t), sizeof(char), cmp2);
    if(strcmp(s,t)<0) puts("Yes");
    else puts("No");
    return 0;
}
