#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
int a,s,d,f,g,h,j,i;
scanf("%d",&a);
if(a%10==9) printf("Yes\n");
else if(a/10==9) printf("Yes\n");
else printf("No\n");
return 0;
}
