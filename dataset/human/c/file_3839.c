#include <stdio.h>
#include<math.h>

int main()
{
    int a,b,t,i;
    scanf("%d%d",&a,&b);
    if(a>b){
        t=a;
        a=b;
        b=t;
    }
    for(i=a;i>0;i--){
        if(b%i==0&&a%i==0){
            break;
        }
    }
    printf("%.f",1.0*a*b/i);
    return 0;
}
