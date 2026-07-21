#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1e9+7
#include <math.h>

int main()
{
    int N,R;
    scanf("%d%d",&N,&R);
    int end;
    if(N<10)
     end=R+100*(10-N);
     else end=R;
     printf("%d\n",end);

    return 0;
}
