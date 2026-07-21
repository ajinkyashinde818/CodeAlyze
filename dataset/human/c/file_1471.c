#include <stdio.h>
#include<math.h>
int main()
{
 long int x,y,z,sum,i=0,k;
 
 scanf("%ld",&x);
while(x>0)
{
    y=x%10;
    x=x/10;
    if(y==9)
    {
        i=1;
        break;
    }
}
if(i==1)
{
    printf("Yes");
}else{
    printf("No");
}
    return 0;
}
