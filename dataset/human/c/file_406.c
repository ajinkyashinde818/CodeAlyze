#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
int main(void)
{
    int N,R;
    scanf("%d %d",&N,&R);

    int sum = R+100*(10-N);
    if (N<10)printf("%d",sum);
    else printf("%d",R);


    return EXIT_SUCCESS;
}
