#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long ll;


int main()
{
    int n,r;
    scanf("%d %d",&n,&r);

    if(n<10)
    {
        r=r+100*(10-n);
    }
    
    printf("%d\n",r);


    return 0;
}
