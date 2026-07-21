#include <stdio.h>
int main(void)
{
    int x,y,a,b;
    while(1)
    {
    scanf("%d%d",&y,&x);
    if(x==0 && y==0)
    {
        break;
    }
        for(a=1;a<=y;a++)
        {
            if(a%2==1){
            for(b=1;b<=x;b++)
            {
                if(b%2==0)
                    printf(".");
                else
                    printf("#");
            }
            }
            else
            {
                for(b=1;b<=x;b++)
                {
                    if(b%2==0)
                        printf("#");
                    else
                        printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
