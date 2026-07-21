#include<stdio.h>
int main(){
  int i,j,s,n[2],a=0,c=0;
  scanf("%d",&s);
   scanf("%d",&n[0]);
    scanf("%d",&n[1]);
    a=n[1]-n[0];
    if(n[0]>n[1]) n[0]=n[1];
  for(i=2;i<s;i++){
    scanf("%d",&n[1]);
      c=n[1]-n[0];
      if(a<c)a=c;
      if(n[0]>n[1]) n[0]=n[1];
    }
  printf("%d\n",a);
  return 0;
}
