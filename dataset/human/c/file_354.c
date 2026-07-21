#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y)(x>y?x:y)
#define min(x,y)(x>y?y:x)
typedef long long int ll;
typedef unsigned long long int ull;
ll gcd(ll x,ll y){if(!y)return x;return gcd(y,x%y);}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
void swap(ll *x,ll *y){ll tmp=*x;*x=*y;*y=tmp;}
int asc_cmp(const void* X,const void* Y){ll x=*(int*)X,y=*(int*)Y;if(x<y)return -1;else if(x==y)return 0;else return 1;}
int desc_cmp(const void* X,const void* Y){ll x=*(int*)X,y=*(int*)Y;if(x<y)return 1;else if(x==y)return 0;else return -1;}

int main(){
    int n,r;scanf("%d %d",&n,&r);
    if(n<=10){
        printf("%d\n",100*(10-n)+r);
    }else{
        printf("%d\n",r);
    }
}
