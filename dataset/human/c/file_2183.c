#include<stdio.h>
#include<string.h>
int main(){
  char s[100001];
  int q,i,rev=0,len;
  scanf("%s",s);
  scanf("%d",&q);
  len=strlen(s);
  char be[q+1],af[q+1];
  int benum=0,afnum=0;
  int t[q+1],f;
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
    if(t[i]==1)
      rev++;
    else{
      scanf("%d ",&f);
      if((rev+f)%2==0)
        scanf("%c",&af[afnum++]);
      else
        scanf("%c",&be[benum++]);
    }
  }
  if(rev%2==0){
    for(i=benum-1;i>=0;i--)
      printf("%c",be[i]);
    for(i=0;i<len;i++)
      printf("%c",s[i]);
    for(i=0;i<afnum;i++)
      printf("%c",af[i]);
    }
  else{
    for(i=afnum-1;i>=0;i--)
      printf("%c",af[i]);
    for(i=len-1;i>=0;i--)
      printf("%c",s[i]);
    for(i=0;i<benum;i++)
      printf("%c",be[i]);
    }
  return 0;
}
