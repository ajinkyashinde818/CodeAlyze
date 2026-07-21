/*よくばりセット2019/07/13 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MOD 1000000007
typedef long long int ll;
void llswap(ll *x,ll *y){ll temp;temp=*x;*x=*y;*y=temp;}
void swap(int *x,int *y){int tmp;tmp=*x;*x=*y;*y=tmp;}
int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x>y?y:x;}
ll llmax(ll x,ll y){return x>y?x:y;}
ll llmin(ll x,ll y){return x>y?y:x;}
int asc(const void *a,const void *b){return *(int*)a-*(int*)b;}
int desc(const void *a,const void *b){return *(int*)b-*(int*)a;}

int main(){
    int w;
    scanf("%d",&w);
    printf("%d\n",w*32);
    return 0;
}
