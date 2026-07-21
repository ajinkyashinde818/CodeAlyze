#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, r, t,c1,c2;

    scanf("%d %d", &n, &r);

    c1=((n>=1)&&(n<=100));
    c2=((r>=0)&&(r<=4111));

    if(c1 && c2){
        if(n>=10){
            printf("%d",r);
        }else{
            t=r+(100*(10-n));
            printf("%d",t);

        }
    }

    return 0;
}
