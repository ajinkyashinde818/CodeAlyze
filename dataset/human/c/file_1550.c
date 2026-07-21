#include<stdio.h>

int main(){
int a,b;
char c,c1;
scanf("%c %c",&c,&c1);
if(c=='A')a=0;
if(c=='B')a=1;
if(c=='C')a=2;
if(c=='D')a=3;
if(c=='E')a=4;
if(c=='F')a=5;
if(c1=='A')b=0;
if(c1=='B')b=1;
if(c1=='C')b=2;
if(c1=='D')b=3;
if(c1=='E')b=4;
if(c1=='F')b=5;
//printf("%d%d%c%c",a,b,c,c1);
if(a>b)puts(">");
if(a==b)puts("=");
if(a<b)puts("<");
return 0;
}
