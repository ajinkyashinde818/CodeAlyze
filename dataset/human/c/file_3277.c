#include <stdio.h>
int main (){
  int a,b,c[200000],d[199999],max=0,ans;
  scanf("%d%d\n",&a,&b);
  for(int i=0;i<b;i++)
    scanf("%d",&c[i]);
  for(int i=0;i<b-1;i++){
    d[i]=c[i+1]-c[i];
    if (max<d[i])
      max=d[i];
    }
   if (max<c[0]+a-c[b-1])
     max=c[0]+a-c[b-1];
    ans=a-max;
    printf("%d",ans);
    
  return 0;
  }
