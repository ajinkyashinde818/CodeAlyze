#include <stdio.h>
int main(void)
{
    long int n, m, ans[100001]={0}, a[100000], i, j=0;
    scanf("%ld%ld", &n, &m);
    for(i=0;i<m;i++){
        scanf("%ld", &a[i]);
    }

    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    if(n==1){
        printf("%ld\n", ans[1]);
        return 0;
    }
    for(i=0;i<=n;i++){
        if(a[j]==i){
            ans[i]=0;
            if(j!=m-1) j++;
        }
        else if(i==0) ans[i]=0;
        else if(i==1) ans[i]=1;
        else if(i==2 && ans[1]!=0) ans[i]=2;
        else if(i==2 && ans[1]==0) ans[i]=1;
        else ans[i]=ans[i-1]+ans[i-2];
        ans[i]=ans[i]%1000000007;
    }
    printf("%ld\n", ans[i-1]);
    
    return 0;
}
