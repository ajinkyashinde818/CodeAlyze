#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{   
    int n;
    scanf("%d",&n);
    int a[50],b[50],c[50];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n-1;i++){
        scanf("%d",&c[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=b[a[i]-1];
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1]==a[i]+1){
            ans+=c[a[i]-1];
        }
    }
   
    printf("%d",ans);

    return 0;
}
