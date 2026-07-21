#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define max(x,y)(x>y?x:y)
#define min(x,y)(x>y?y:x)
typedef long long int ll;
typedef unsigned long long int ull;
int asc_cmp(const void* X,const void* Y){int x=*(int*)X,y=*(int*)Y;if(x<y)return -1;else if(x==y)return 0;else return 1;}
int desc_cmp(const void* X,const void* Y){int x=*(int*)X,y=*(int*)Y;if(x<y)return 1;else if(x==y)return 0;else return -1;}

int main(){
    int n;scanf("%d",&n);
    int a[n];for(int i=0;i<n;i++)scanf("%d",&a[i]);
    int b[n];for(int i=0;i<n;i++)scanf("%d",&b[i]);
    int c[n-1];for(int i=0;i<n-1;i++)scanf("%d",&c[i]);

    int ans=0,before;
    ans+=b[a[0]-1];
    before=a[0];
    for(int i=1;i<n;i++){
        ans+=b[a[i]-1];
        if(before+1==a[i])ans+=c[before-1];
        before=a[i];
    }
    printf("%d\n",ans);
}
