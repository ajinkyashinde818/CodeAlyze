#include<stdio.h>
int main(){int k,s;scanf("%d%d",&k,&s);int a=0;for(int i=0;i<=k;i++){for(int j=0;j<=k;j++){int p=s-i-j;if(p>=0 && p<=k)a++;}}printf("%d",a);}
