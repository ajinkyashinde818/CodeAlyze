#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#define ll long long

int main()
{
    int A , B , K;
    int min=0;
    scanf("%d %d %d",&A,&B,&K);

    if (A>B)min=B;
    else min=A;

    int array[min];
    int idx=1;

    for (int i=min;i>=1;i--)
    {
       if (A%i==0 && B%i==0)
       {
           array[idx]=i;
           idx++;
       }
    }

    printf("%d",array[K]);


    return 0;
}
