#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
    long long int n;
    scanf("%lld",&n);
    long long int a[n],i;
    long long int sum=0;
    long long int sigma=(n*(n+1))/2;
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(sum%sigma!=0)printf("NO");
    else{
        while(a[1]>=1){
            long long int min=a[1],minnum=1;
            for(i=2;i<=n;i++){
                if(a[i]<min){
                    min=a[i];
                    minnum=i;
                }
            }
            for(i=1;i<=minnum-1;i++)a[i]-=n-minnum+1+i;
            for(i=minnum;i<=n;i++)a[i]-=i-minnum+1;
        }
        int flag=0;
        for(i=1;i<=n;i++)if(a[i]!=0)flag=1;
        if(flag==0)printf("YES");
        else printf("NO");
    }
    return 0;
}
