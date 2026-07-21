#include "stdio.h"

int main()
{
while(1)
{
int y,x;
scanf("%d %d",&y,&x);
if(y == 0 && x == 0)
{
break;
}
for(int i = 0; i < y; i++)
{
for(int ii = 0; ii < x; ii++)
{
if((i + ii) % 2 == 0)
{
printf("#");
}
else
{
printf(".");
}
}
printf("\n");
}
printf("\n");
}
return 0;
}
