#include "stdio.h"

int main(void)
{
    int ensyu=0;
    int kensu=0;
    int i;

    scanf("%d",&ensyu);
    scanf("%d",&kensu);

    int m[kensu];
    for(i=0;i < kensu;i++)
    {
        scanf("%d",&m[i]);
    }

    int a[kensu];
    for(i=0;i<kensu-1;i++)
    {
        a[i]=m[i+1]-m[i];
    }
    a[kensu-1] = ensyu-m[kensu-1]+m[0];

    int maxa=0;
    for(i=0;i<kensu;i++)
    {
        if(maxa <a[i])
        {
            maxa = a[i];
        }
    }

    int kyori=0;
    for(i=0;i<kensu;i++)
    {
        kyori= kyori+a[i];
    }
    kyori=kyori-maxa;

    printf("%d",kyori);
}
