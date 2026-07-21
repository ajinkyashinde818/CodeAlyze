#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
char s[1000010];
int i,x,d[1000010][2]={0,1};
int main(){
  scanf("%s",s);
  for(i=0;s[i];i++){
    x=s[i]-'0';
    d[i+1][0]=MIN(d[i][0]+x  ,d[i][1]+10-x);
    d[i+1][1]=MIN(d[i][0]+x+1,d[i][1]+9 -x);
  }
  printf("%d\n",d[i][0]);
  return 0;
}
