#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(void){
int n,k;
int h[1000000];
int yes=0;
int count;
scanf("%d",&n);
scanf("%d",&k);
for(count=0;count!=n;count++)
{
    scanf("%d",&h[count]);
}
for(int count=0;count!=n;count++)
{
    if(h[count]>=k){yes++;}
}
printf("%d",yes);
return 0;
}
