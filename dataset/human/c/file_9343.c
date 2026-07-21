#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{   int n,d,x,sum;
    scanf("%d%d%d",&n,&d,&x);
    int a[200];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sum=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<100;j++){
            if(j*a[i]+1>d)
                break;
            else
                sum+=1;
        }
    }
    printf("%d",sum+n+x);
    return 0;
}
