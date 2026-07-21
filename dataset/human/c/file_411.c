#include<stdio.h>
#include<stdlib.h>
int main(){
int N, DispR;
int InnR;
scanf("%d", &N);
scanf("%d", &DispR);
if(N>=10)
{
InnR = DispR;
printf("%d", InnR);
}
else
{
InnR = DispR + 100*(10-N);
printf("%d", InnR);
}
return 0;
}
