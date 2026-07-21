#include<stdio.h>
char s[500050],c;
int main(){
  int t=200010,r,i,n,q,f=1;
  scanf("%s %d",s+t,&n);
  for(r=t;s[r];r++);
  while(n--){
    scanf("%d",&q);
    if(q==1)f=1-f;
    else{
      scanf("%d %c",&q,&c);
      if(q%2==f)s[--t]=c;
      else      s[r++]=c;
    }
  }
  if(f){
    for(i=t;i<r;i++)printf("%c",s[i]);
  }
  else{
    for(i=r;i>t;i--)printf("%c",s[i-1]);
  }
  printf("\n");
  return 0;
}
