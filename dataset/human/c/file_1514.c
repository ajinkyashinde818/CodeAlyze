#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#define INFINI 100000001


int main(){

char a,b;
scanf("%c %c",&a,&b);

if(a>b)printf(">");
else if(a<b)printf("<");
else printf("=");

return 0;
}
