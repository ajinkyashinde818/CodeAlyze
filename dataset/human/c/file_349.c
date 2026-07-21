#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int x,m;
    scanf("%d %d",&x,&m);
    if(x<10)
    {
        m=m+(100*(10-x));
    }
    printf("%d\n",m);



    return 0;
}
