#include<stdio.h>
int main(){int a,b;while(scanf("%d%d",&a,&b),a+b){
for(int i=0;i<a;i++,printf("\n"))for(int j=0;j<b;j++)
printf("%s",(j+i)%2?".":"#");printf("\n");}}
