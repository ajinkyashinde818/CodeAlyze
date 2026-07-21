#include<stdio.h>

int main(){

int k,s;

scanf("%d %d",&k,&s);



int a,b,c;

int ans=0;

for(a=0;a<=k;a++){

for(b=0;b<=k;b++){

if(a+b<=s&&s-a-b<=k)
 ans++;


}}



printf("%d\n",ans);



return 0;}
