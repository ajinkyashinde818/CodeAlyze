#include <stdio.h>
#include <string.h>


int main()
{
    int A,B,C;
    while(scanf("%d%d%d",&A,&B,&C)!=EOF){
    if(C<=A+B)
        printf("%d\n",B+C);
    else
        printf("%d\n",A+B*2+1);
    }
    return 0;
}
