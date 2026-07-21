/*2019/09/13 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MOD 1000000007
#define MIN 999999999
#define MAX -999999999
typedef long long int ll;
typedef unsigned long long int ull;
void llswap(ll *x,ll *y){ll tmp;tmp=*x;*x=*y;*y=tmp;}
void swap(int *x,int *y){int tmp;tmp=*x;*x=*y;*y=tmp;}
int rmax(int x,int y){return x>y?x:y;}
int rmin(int x,int y){return x>y?y:x;}
ll llrmax(ll x,ll y){return x>y?x:y;}
ll llrmin(ll x,ll y){return x>y?y:x;}
int asc(const void *a,const void *b){return *(int*)a-*(int*)b;}
int desc(const void *a,const void *b){return *(int*)b-*(int*)a;}
int llasc(const void *a,const void *b){return *(ll*)a-*(ll*)b;}
int lldesc(const void *a,const void *b){return *(ll*)b-*(ll*)a;}
int gcd(int x,int y){if(y==0)return x;return gcd(y,x%y);}
/*
int asc_t(const void *a,const void *b){return ((struct_t*)a)->member - ((struct_t*)b)->member;}
int desc_t(const void *a,const void *b){return ((struct_t*)b)->member - ((struct_t*)a)->member;}
*/
int main(){
    int n,k;
    int h[200000];
    int cnt=0;

    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
        if(k<=h[i]){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
