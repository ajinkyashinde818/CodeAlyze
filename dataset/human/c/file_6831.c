#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define max(x,y)(x>y?x:y)
#define min(x,y)(x>y?y:x)
typedef long long int ll;
typedef unsigned long long int ull;;
int asc_cmp(const void* X,const void* Y){int x=*(int*)X,y=*(int*)Y;if(x<y)return -1;else if(x==y)return 0;else return 1;}
int desc_cmp(const void* X,const void* Y){int x=*(int*)X,y=*(int*)Y;if(x<y)return 1;else if(x==y)return 0;else return -1;}
void println(){printf("\n");}

int main(){
    int n;scanf("%d",&n);
    int a[3*n];for(int i=0;i<3*n;i++)scanf("%d",&a[i]);

    qsort(a,3*n,sizeof(int),desc_cmp);
    
    ll ans=0; 
    for(int i=1;i<2*n;i+=2){
        ans+=a[i];
    }
    printf("%lld\n",ans);
}
