#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,t,i,z,k;
    int a[100010];
    while(scanf("%d",&n)!=EOF){
        t=1;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        z=a[1];
        for(i=1;i<n;i++){
            if(z!=2){
                z=a[z];
                t++;
            }
            else {printf("%d\n",t);break;}
        }
        if(i==n)printf("-1\n");

    }
    return 0;
}
