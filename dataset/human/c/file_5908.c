#include<stdio.h>
int main(){
  int a,b,n,mini;
  int i,c,shiro;
  scanf("%d",&n);
  scanf("%d%d",&a,&b);
  shiro=b-a;
  if(a<=b)mini = a;
  else mini = b;
  for(i=2;i<n;i++){
    scanf("%d",&c);
    if(c<mini)mini=c;
    else if(shiro<c-mini)shiro=c-mini;
  }    
printf("%d\n",shiro);
return 0;
}
